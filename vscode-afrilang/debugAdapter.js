#!/usr/bin/env node
'use strict';

const { DebugSession, InitializedEvent, TerminatedEvent, StoppedEvent,
  OutputEvent, Thread, StackFrame, Scope, Source, Variable } = require('@vscode/debugadapter');
const { spawn, execFile } = require('child_process');
const fs = require('fs');
const path = require('path');
const { promisify } = require('util');

const execFileAsync = promisify(execFile);

class AfrilangDebugSession extends DebugSession {
  constructor() {
    super();
    this._gdb = null;
    this._gdbBuf = '';
    this._pending = new Map();
    this._token = 1;
    this._threads = [new Thread(1, 'main')];
    this._stopped = false;
    this._executable = '';
    this._sourceFile = '';
    this._debugMeta = null;
  }

  _findMeta(name, scopeHint) {
    if (!this._debugMeta?.variables) return null;
    const matches = this._debugMeta.variables.filter((v) => v.name === name);
    if (!matches.length) return null;
    if (scopeHint) {
      const scoped = matches.find((v) => v.scope === scopeHint);
      if (scoped) return scoped;
    }
    const local = matches.find((v) => v.scope && v.scope !== 'global');
    return local || matches[0];
  }

  _formatValue(raw, type) {
    if (raw == null || raw === '?') return '?';
    const text = String(raw);
    const t = (type || '').toLowerCase();
    if (t === 'text' || t === 'string') {
      if (text.startsWith('"') && text.endsWith('"')) {
        return text.slice(1, -1).replace(/\\"/g, '"').replace(/\\n/g, '\n');
      }
      const m = text.match(/^0x[0-9a-f]+ "(.*)"$/i);
      if (m) return m[1];
      return text;
    }
    if (t === 'bool' || t === 'boolean') {
      if (text === '1' || text === 'true') return 'true';
      if (text === '0' || text === 'false') return 'false';
    }
    if (t === 'int' || t === 'float' || t === 'number') {
      const n = Number(text);
      if (!Number.isNaN(n)) return String(n);
    }
    return text;
  }

  initializeRequest(response) {
    response.body = response.body || {};
    response.body.supportsConfigurationDoneRequest = true;
    response.body.supportsSetVariable = false;
    response.body.supportsEvaluateForHovers = false;
    this.sendResponse(response);
    this.sendEvent(new InitializedEvent());
  }

  async configurationDoneRequest(response) {
    this.sendResponse(response);
    try {
      await this._launchGdb();
    } catch (err) {
      this.sendEvent(new OutputEvent(String(err.message || err) + '\n', 'stderr'));
      this.sendEvent(new TerminatedEvent());
    }
  }

  launchRequest(response, args) {
    this._doLaunch(response, args).catch((err) => {
      this.sendEvent(new OutputEvent(String(err.message || err) + '\n', 'stderr'));
      response.success = false;
      this.sendResponse(response);
      this.sendEvent(new TerminatedEvent());
    });
  }

  async _doLaunch(response, args) {
    this._sourceFile = path.resolve(args.program);
    const afrilangPath = args.afrilangPath || 'afrilang';
    const cwd = args.cwd || path.dirname(this._sourceFile);
    const base = path.basename(this._sourceFile, '.afr');
    this._executable = path.join(cwd, base);

    try {
      await execFileAsync(afrilangPath, ['run', this._sourceFile, '--emit'], { cwd });
    } catch (err) {
      const msg = (err.stderr || err.stdout || err.message || '').toString();
      throw new Error('Compilation échouée:\n' + msg);
    }

    if (!fs.existsSync(this._executable)) {
      throw new Error('Exécutable introuvable: ' + this._executable);
    }

    const metaPath = this._executable + '.afr.debug.json';
    if (fs.existsSync(metaPath)) {
      try {
        this._debugMeta = JSON.parse(fs.readFileSync(metaPath, 'utf8'));
      } catch {
        this._debugMeta = null;
      }
    }

    response.success = true;
    this.sendResponse(response);
  }

  async setBreakPointsRequest(response, args) {
    const breakpoints = [];
    for (const req of args.breakpoints || []) {
      const file = req.source.path || this._sourceFile;
      try {
        await this._gdbCommand(`-break-insert ${file}:${req.line}`);
        breakpoints.push({
          verified: true,
          line: req.line,
          source: new Source(path.basename(file), file)
        });
      } catch {
        breakpoints.push({ verified: false, line: req.line });
      }
    }
    response.body = { breakpoints };
    this.sendResponse(response);
  }

  continueRequest(response) {
    this._gdbCommand('-exec-continue').then(() => {
      this.sendResponse(response);
    }).catch((err) => {
      this.sendEvent(new OutputEvent(String(err) + '\n', 'stderr'));
      this.sendResponse(response);
    });
  }

  nextRequest(response) {
    this._gdbCommand('-exec-next').then(() => {
      this.sendResponse(response);
    }).catch((err) => {
      this.sendEvent(new OutputEvent(String(err) + '\n', 'stderr'));
      this.sendResponse(response);
    });
  }

  stepInRequest(response) {
    this._gdbCommand('-exec-step').then(() => {
      this.sendResponse(response);
    }).catch((err) => {
      this.sendEvent(new OutputEvent(String(err) + '\n', 'stderr'));
      this.sendResponse(response);
    });
  }

  stepOutRequest(response) {
    this._gdbCommand('-exec-finish').then(() => {
      this.sendResponse(response);
    }).catch((err) => {
      this.sendEvent(new OutputEvent(String(err) + '\n', 'stderr'));
      this.sendResponse(response);
    });
  }

  threadsRequest(response) {
    response.body = { threads: this._threads };
    this.sendResponse(response);
  }

  async stackTraceRequest(response, args) {
    try {
      const result = await this._gdbCommand('-stack-list-frames');
      const frames = [];
      const frameList = result?.frame || [];
      const items = Array.isArray(frameList) ? frameList : [frameList];
      let id = 0;
      for (const fr of items) {
        if (!fr) continue;
        const line = parseInt(fr.line || '0', 10) || 1;
        const file = fr.file || fr.fullname || this._sourceFile;
        frames.push(new StackFrame(
          id++,
          fr.func || fr.function || '?',
          new Source(path.basename(file), file),
          line,
          parseInt(fr.col || '1', 10) || 1
        ));
      }
      response.body = { stackFrames: frames, totalFrames: frames.length };
    } catch {
      response.body = { stackFrames: [], totalFrames: 0 };
    }
    this.sendResponse(response);
  }

  scopesRequest(response, args) {
    const scopes = [new Scope('Locals', args.frameId * 1000, false)];
    if (this._debugMeta?.variables?.length) {
      scopes.push(new Scope('Globals (AFRILANG)', args.frameId * 1000 + 1, false));
    }
    response.body = { scopes };
    this.sendResponse(response);
  }

  async variablesRequest(response, args) {
    const variables = [];
    const ref = args.variablesReference;
    const frameId = Math.floor(ref / 1000);
    const kind = ref % 1000;

    if (kind === 1 && this._debugMeta?.variables) {
      for (const entry of this._debugMeta.variables) {
        try {
          const result = await this._gdbCommand(`-data-evaluate-expression ${entry.name}`);
          const value = this._formatValue(result?.value, entry.type);
          variables.push(new Variable(`${entry.name} : ${entry.type}`, value));
        } catch {
          variables.push(new Variable(`${entry.name} : ${entry.type}`, '?'));
        }
      }
      response.body = { variables };
      this.sendResponse(response);
      return;
    }

    try {
      const result = await this._gdbCommand(
        `-stack-list-variables ${frameId} --simple-values`
      );
      const list = result?.variables || [];
      const items = Array.isArray(list) ? list : [list];
      for (const v of items) {
        if (!v || !v.name) continue;
        const meta = this._findMeta(v.name);
        const label = meta ? `${v.name} : ${meta.type}` : v.name;
        const value = this._formatValue(v.value, meta?.type);
        variables.push(new Variable(label, value ?? '?'));
      }
    } catch {
      /* ignore */
    }
    response.body = { variables };
    this.sendResponse(response);
  }

  disconnectRequest(response) {
    this._stopGdb();
    this.sendResponse(response);
    this.sendEvent(new TerminatedEvent());
  }

  terminateRequest(response) {
    this._stopGdb();
    this.sendResponse(response);
    this.sendEvent(new TerminatedEvent());
  }

  async _launchGdb() {
    const args = ['--interpreter=mi2', '-q', this._executable];
    this._gdb = spawn('gdb', args, { cwd: path.dirname(this._executable) });
    this._gdb.stdout.on('data', (chunk) => this._onGdbData(chunk.toString()));
    this._gdb.stderr.on('data', (chunk) => {
      this.sendEvent(new OutputEvent(chunk.toString(), 'stderr'));
    });
    this._gdb.on('exit', () => {
      this._gdb = null;
      this.sendEvent(new TerminatedEvent());
    });
    await this._gdbCommand('-gdb-version');
    await this._gdbCommand('-exec-run');
  }

  _onGdbData(text) {
    this._gdbBuf += text;
    let idx;
    while ((idx = this._gdbBuf.indexOf('\n')) >= 0) {
      const line = this._gdbBuf.slice(0, idx);
      this._gdbBuf = this._gdbBuf.slice(idx + 1);
      this._handleGdbLine(line);
    }
  }

  _handleGdbLine(line) {
    if (line.startsWith('~')) {
      const msg = line.slice(2, -1).replace(/\\n/g, '\n');
      if (msg.trim()) this.sendEvent(new OutputEvent(msg + '\n', 'stdout'));
      return;
    }
    if (line.startsWith('*stopped')) {
      this._stopped = true;
      const reason = line.includes('breakpoint-hit') ? 'breakpoint'
        : line.includes('end-stepping-range') ? 'step'
        : 'pause';
      this.sendEvent(new StoppedEvent(reason, 1));
      return;
    }
    const match = line.match(/^(\d+)\^/);
    if (match) {
      const token = parseInt(match[1], 10);
      const pending = this._pending.get(token);
      if (!pending) return;
      this._pending.delete(token);
      if (line.includes(',error,')) {
        pending.reject(line);
      } else {
        const payload = this._parseMiResult(line);
        pending.resolve(payload);
      }
    }
  }

  _parseMiResult(line) {
    const eq = line.indexOf('=');
    if (eq < 0) return {};
    const rest = line.slice(eq + 1);
    try {
      return this._parseMiValue(rest);
    } catch {
      return {};
    }
  }

  _parseMiValue(input) {
    const out = {};
    let i = 0;
    while (i < input.length) {
      while (i < input.length && (input[i] === ',' || input[i] === ' ')) i++;
      const keyStart = i;
      while (i < input.length && input[i] !== '=') i++;
      if (i >= input.length) break;
      const key = input.slice(keyStart, i);
      i++;
      const { value, next } = this._readMiToken(input, i);
      out[key] = value;
      i = next;
    }
    return out;
  }

  _readMiToken(input, start) {
    if (input[start] === '"') {
      let i = start + 1;
      let value = '';
      while (i < input.length) {
        if (input[i] === '\\' && i + 1 < input.length) {
          value += input[i + 1];
          i += 2;
        } else if (input[i] === '"') {
          return { value, next: i + 1 };
        } else {
          value += input[i++];
        }
      }
      return { value, next: i };
    }
    if (input[start] === '{') {
      let depth = 0;
      let i = start;
      for (; i < input.length; i++) {
        if (input[i] === '{') depth++;
        else if (input[i] === '}') {
          depth--;
          if (depth === 0) {
            const inner = input.slice(start + 1, i);
            return { value: this._parseMiValue(inner), next: i + 1 };
          }
        }
      }
      return { value: {}, next: i };
    }
    let i = start;
    while (i < input.length && input[i] !== ',' && input[i] !== ' ') i++;
    const raw = input.slice(start, i);
    const num = Number(raw);
    return { value: Number.isNaN(num) ? raw : num, next: i };
  }

  _gdbCommand(cmd) {
    return new Promise((resolve, reject) => {
      if (!this._gdb) {
        reject(new Error('GDB non démarré'));
        return;
      }
      const token = this._token++;
      this._pending.set(token, { resolve, reject });
      this._gdb.stdin.write(token + cmd + '\n');
      setTimeout(() => {
        if (this._pending.has(token)) {
          this._pending.delete(token);
          reject(new Error('Timeout GDB: ' + cmd));
        }
      }, 15000);
    });
  }

  _stopGdb() {
    if (this._gdb) {
      try { this._gdb.kill(); } catch { /* ignore */ }
      this._gdb = null;
    }
  }
}

DebugSession.run(AfrilangDebugSession);
