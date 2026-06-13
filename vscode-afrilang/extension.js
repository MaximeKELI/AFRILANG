const vscode = require('vscode');
const path = require('path');
const fs = require('fs');
const { exec } = require('child_process');
const { promisify } = require('util');
const { LanguageClient, TransportKind, DidOpenTextDocumentNotification } = require('vscode-languageclient/node');

const execAsync = promisify(exec);

/** @type {LanguageClient | undefined} */
let client;

/** @type {vscode.OutputChannel | undefined} */
let outputChannel;

function isAfrilangDocument(document) {
  if (!document) return false;
  return document.languageId === 'afrilang' || document.fileName.endsWith('.afr');
}

function resolveServerPath(context) {
  const candidates = [];

  const addCandidate = (p) => {
    if (p && !candidates.includes(p)) candidates.push(p);
  };

  // 1. Bundled with extension (symlink → repo/build/afrilang) — priorité max
  if (context?.extensionPath) {
    addCandidate(path.join(context.extensionPath, '..', 'build', 'afrilang'));
  }

  // 2. Settings utilisateur / workspace
  const config = vscode.workspace.getConfiguration('afrilang');
  const configured = config.get('serverPath', '');
  const folders = vscode.workspace.workspaceFolders ?? [];

  if (configured) {
    for (const folder of folders) {
      addCandidate(configured.replace(/\$\{workspaceFolder\}/g, folder.uri.fsPath));
    }
    if (!configured.includes('${workspaceFolder}')) {
      addCandidate(configured);
    }
  }

  // 3. Workspace build/afrilang
  for (const folder of folders) {
    addCandidate(path.join(folder.uri.fsPath, 'build', 'afrilang'));
  }

  for (const candidate of candidates) {
    if (fs.existsSync(candidate)) return candidate;
  }

  return configured || 'afrilang';
}

function verifyServerPath(serverPath) {
  if (serverPath === 'afrilang') return false;
  return fs.existsSync(serverPath);
}

function getOutputChannel() {
  if (!outputChannel) {
    outputChannel = vscode.window.createOutputChannel('AFRILANG');
  }
  return outputChannel;
}

async function runAfrilangCommand(context, subcommand, filePath) {
  const serverPath = resolveServerPath(context);

  if (!verifyServerPath(serverPath)) {
    const msg = `Exécutable introuvable : ${serverPath}\n` +
      'Compilez le projet (cd build && make) ou configurez afrilang.serverPath.';
    vscode.window.showErrorMessage(msg);
    getOutputChannel().appendLine(msg);
    return;
  }

  const channel = getOutputChannel();
  channel.clear();
  channel.show(true);
  channel.appendLine(`> "${serverPath}" ${subcommand} "${filePath}"`);
  channel.appendLine('');

  try {
    const { stdout, stderr } = await execAsync(
      `"${serverPath}" ${subcommand} "${filePath}"`,
      { cwd: path.dirname(filePath), maxBuffer: 10 * 1024 * 1024 }
    );
    if (stdout) channel.appendLine(stdout);
    if (stderr) channel.appendLine(stderr);
    channel.appendLine('');
    channel.appendLine('--- Terminé ---');
  } catch (err) {
    if (err.stdout) channel.appendLine(err.stdout);
    if (err.stderr) channel.appendLine(err.stderr);
    channel.appendLine(`Erreur (code ${err.code ?? '?'}): ${err.message}`);
    vscode.window.showErrorMessage(`AFRILANG: échec de ${subcommand}`);
  }
}

async function scanWorkspaceFiles(client) {
  if (!client || !vscode.workspace.workspaceFolders?.length) return;

  const files = await vscode.workspace.findFiles('**/*.afr', '{**/node_modules/**,**/build/**}');
  getOutputChannel().appendLine(`AFRILANG: analyse de ${files.length} fichier(s) .afr...`);

  for (const uri of files) {
    try {
      const doc = await vscode.workspace.openTextDocument(uri);
      client.sendNotification(DidOpenTextDocumentNotification.type, {
        textDocument: {
          uri: uri.toString(),
          languageId: 'afrilang',
          version: 1,
          text: doc.getText()
        }
      });
    } catch (err) {
      getOutputChannel().appendLine(`  skip ${uri.fsPath}: ${err.message}`);
    }
  }
}

function startLanguageClient(context) {
  const serverPath = resolveServerPath(context);

  getOutputChannel().appendLine(`AFRILANG: serveur → ${serverPath}`);

  if (!verifyServerPath(serverPath)) {
    const msg = `AFRILANG LSP: exécutable introuvable (${serverPath}). ` +
      'Définissez afrilang.serverPath dans settings.json.';
    vscode.window.showWarningMessage(msg);
    getOutputChannel().appendLine(msg);
    return Promise.resolve();
  }

  const serverOptions = {
    command: serverPath,
    args: ['lsp'],
    transport: TransportKind.stdio,
    options: { cwd: vscode.workspace.workspaceFolders?.[0]?.uri.fsPath }
  };

  const clientOptions = {
    documentSelector: [{ scheme: 'file', language: 'afrilang' }],
    synchronize: {
      fileEvents: vscode.workspace.createFileSystemWatcher('**/*.afr')
    },
    outputChannel: getOutputChannel()
  };

  client = new LanguageClient(
    'afrilang',
    'AFRILANG Language Server',
    serverOptions,
    clientOptions
  );
  return client.start().then(() => {
    scanWorkspaceFiles(client);
    const watcher = vscode.workspace.createFileSystemWatcher('**/*.afr');
    const refresh = async (uri) => {
      if (!client || !uri) return;
      try {
        const doc = await vscode.workspace.openTextDocument(uri);
        client.sendNotification(DidOpenTextDocumentNotification.type, {
          textDocument: {
            uri: uri.toString(),
            languageId: 'afrilang',
            version: doc.version,
            text: doc.getText()
          }
        });
      } catch (_) { /* ignore */ }
    };
    watcher.onDidCreate(refresh);
    watcher.onDidChange(refresh);
    context.subscriptions.push(watcher);
  });
}

function registerRunCommand(context) {
  const disposable = vscode.commands.registerCommand('afrilang.runFile', async () => {
    const editor = vscode.window.activeTextEditor;
    if (!editor || !isAfrilangDocument(editor.document)) {
      vscode.window.showWarningMessage('Ouvrez un fichier .afr pour l\'exécuter.');
      return;
    }

    await editor.document.save();
    await runAfrilangCommand(context, 'run', editor.document.uri.fsPath);
  });
  context.subscriptions.push(disposable);
}

function registerCheckCommand(context) {
  const disposable = vscode.commands.registerCommand('afrilang.checkFile', async () => {
    const editor = vscode.window.activeTextEditor;
    if (!editor || !isAfrilangDocument(editor.document)) {
      vscode.window.showWarningMessage('Ouvrez un fichier .afr pour le vérifier.');
      return;
    }

    await editor.document.save();
    await runAfrilangCommand(context, 'check', editor.document.uri.fsPath);
  });
  context.subscriptions.push(disposable);
}

function registerRestartCommand(context) {
  const disposable = vscode.commands.registerCommand('afrilang.restartServer', async () => {
    if (client) {
      await client.stop();
      client = undefined;
    }
    await startLanguageClient(context);
    vscode.window.showInformationMessage('Serveur AFRILANG redémarré.');
  });
  context.subscriptions.push(disposable);
}

/** @param {vscode.ExtensionContext} context */
function activate(context) {
  registerRunCommand(context);
  registerCheckCommand(context);
  registerRestartCommand(context);
  startLanguageClient(context).catch((err) => {
    vscode.window.showErrorMessage(`AFRILANG LSP: ${err.message}`);
    getOutputChannel().appendLine(`LSP error: ${err.message}`);
  });
}

function deactivate() {
  if (!client) return undefined;
  return client.stop();
}

module.exports = { activate, deactivate };
