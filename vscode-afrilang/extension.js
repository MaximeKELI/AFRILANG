const vscode = require('vscode');
const path = require('path');
const fs = require('fs');
const { exec } = require('child_process');
const { promisify } = require('util');
const { LanguageClient, TransportKind } = require('vscode-languageclient/node');

const execAsync = promisify(exec);

/** @type {LanguageClient | undefined} */
let client;

/** @type {vscode.OutputChannel | undefined} */
let outputChannel;

/** @type {vscode.DiagnosticCollection | undefined} */
let workspaceDiags;

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

function parseCheckErrors(stderr) {
  const diags = [];
  const withFile = /Erreur dans .+:(\d+):(\d+)\n\s+([^\n]+)/g;
  const withLine = /Erreur ligne (\d+), colonne (\d+)\n\s+([^\n]+)/g;

  for (const re of [withFile, withLine]) {
    let match;
    while ((match = re.exec(stderr)) !== null) {
      const line = Math.max(0, parseInt(match[1], 10) - 1);
      const col = Math.max(0, parseInt(match[2], 10) - 1);
      diags.push(new vscode.Diagnostic(
        new vscode.Range(line, col, line, col + 1),
        match[3].trim(),
        vscode.DiagnosticSeverity.Error,
        'afrilang'
      ));
    }
  }
  return diags;
}

async function checkSingleFile(context, uri) {
  if (!workspaceDiags || !uri) return;

  const serverPath = resolveServerPath(context);
  if (!verifyServerPath(serverPath)) return;

  try {
    await execAsync(
      `"${serverPath}" check "${uri.fsPath}"`,
      { cwd: path.dirname(uri.fsPath), maxBuffer: 10 * 1024 * 1024 }
    );
    workspaceDiags.set(uri, []);
  } catch (err) {
    const text = `${err.stderr ?? ''}${err.stdout ?? ''}`;
    const diags = parseCheckErrors(text);
    if (diags.length) {
      workspaceDiags.set(uri, diags);
    } else if (text.trim()) {
      workspaceDiags.set(uri, [
        new vscode.Diagnostic(
          new vscode.Range(0, 0, 0, 1),
          text.trim(),
          vscode.DiagnosticSeverity.Error,
          'afrilang'
        )
      ]);
    } else {
      workspaceDiags.set(uri, []);
    }
  }
}

async function checkWorkspaceFiles(context) {
  if (!vscode.workspace.workspaceFolders?.length) return;

  const files = await vscode.workspace.findFiles('**/*.afr', '{**/node_modules/**,**/build/**}');
  getOutputChannel().appendLine(`AFRILANG: vérification de ${files.length} fichier(s) .afr...`);

  await Promise.all(files.map((uri) => checkSingleFile(context, uri)));
}

function registerWorkspaceDiagnostics(context) {
  workspaceDiags = vscode.languages.createDiagnosticCollection('afrilang');
  context.subscriptions.push(workspaceDiags);

  const refresh = (uri) => {
    if (uri?.fsPath?.endsWith('.afr')) {
      checkSingleFile(context, uri);
    }
  };

  context.subscriptions.push(
    vscode.workspace.onDidSaveTextDocument((doc) => {
      if (isAfrilangDocument(doc)) checkSingleFile(context, doc.uri);
    })
  );

  const watcher = vscode.workspace.createFileSystemWatcher('**/*.afr');
  watcher.onDidCreate(refresh);
  watcher.onDidChange(refresh);
  watcher.onDidDelete((uri) => workspaceDiags?.delete(uri));
  context.subscriptions.push(watcher);

  checkWorkspaceFiles(context).catch((err) => {
    getOutputChannel().appendLine(`AFRILANG diagnostics: ${err.message}`);
  });
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
  return client.start();
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
    await checkWorkspaceFiles(context);
    vscode.window.showInformationMessage('Serveur AFRILANG redémarré.');
  });
  context.subscriptions.push(disposable);
}

function registerDebugCommand(context) {
  const disposable = vscode.commands.registerCommand('afrilang.debugFile', async () => {
    const editor = vscode.window.activeTextEditor;
    if (!editor || !isAfrilangDocument(editor.document)) {
      vscode.window.showWarningMessage('Ouvrez un fichier .afr pour le débugger.');
      return;
    }

    await editor.document.save();
    const filePath = editor.document.uri.fsPath;
    const serverPath = resolveServerPath(context);
    if (!verifyServerPath(serverPath)) {
      vscode.window.showErrorMessage(`Exécutable introuvable : ${serverPath}`);
      return;
    }

    const terminal = vscode.window.createTerminal({
      name: 'AFRILANG Debug',
      cwd: path.dirname(filePath)
    });
    terminal.show();
    terminal.sendText(`"${serverPath}" debug "${filePath}"`);
  });
  context.subscriptions.push(disposable);
}

async function copyTemplateIfMissing(context, name) {
  const folders = vscode.workspace.workspaceFolders;
  if (!folders?.length) {
    vscode.window.showWarningMessage('Ouvrez un dossier workspace pour initialiser la config debug.');
    return;
  }
  const vscodeDir = path.join(folders[0].uri.fsPath, '.vscode');
  const dest = path.join(vscodeDir, name);
  if (fs.existsSync(dest)) {
    const open = 'Ouvrir';
    const choice = await vscode.window.showInformationMessage(
      `${name} existe déjà.`,
      open
    );
    if (choice === open) {
      const doc = await vscode.workspace.openTextDocument(dest);
      await vscode.window.showTextDocument(doc);
    }
    return;
  }
  const src = path.join(context.extensionPath, 'templates', name);
  if (!fs.existsSync(src)) {
    vscode.window.showErrorMessage(`Modèle introuvable : ${name}`);
    return;
  }
  fs.mkdirSync(vscodeDir, { recursive: true });
  fs.copyFileSync(src, dest);
  const doc = await vscode.workspace.openTextDocument(dest);
  await vscode.window.showTextDocument(doc);
  vscode.window.showInformationMessage(
    `${name} créé. Installez l'extension C/C++ (cppdbg) puis F5 pour débugger.`
  );
}

function registerInitDebugConfigCommand(context) {
  const disposable = vscode.commands.registerCommand('afrilang.initDebugConfig', async () => {
    await copyTemplateIfMissing(context, 'tasks.json');
    await copyTemplateIfMissing(context, 'launch.json');
  });
  context.subscriptions.push(disposable);
}

/** @param {vscode.ExtensionContext} context */
function activate(context) {
  registerRunCommand(context);
  registerCheckCommand(context);
  registerRestartCommand(context);
  registerDebugCommand(context);
  registerInitDebugConfigCommand(context);
  registerWorkspaceDiagnostics(context);
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
