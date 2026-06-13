const vscode = require('vscode');
const path = require('path');
const { LanguageClient, LanguageClientOptions, ServerOptions, TransportKind } = require('vscode-languageclient/node');

/** @type {LanguageClient | undefined} */
let client;

function getServerPath() {
  const config = vscode.workspace.getConfiguration('afrilang');
  return config.get('serverPath', 'afrilang');
}

function startLanguageClient(context) {
  const serverPath = getServerPath();

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
    outputChannelName: 'AFRILANG LSP'
  };

  client = new LanguageClient('afrilang', 'AFRILANG Language Server', serverOptions, clientOptions);
  return client.start();
}

function registerRunCommand(context) {
  const disposable = vscode.commands.registerCommand('afrilang.runFile', async () => {
    const editor = vscode.window.activeTextEditor;
    if (!editor || editor.document.languageId !== 'afrilang') {
      vscode.window.showWarningMessage('Ouvrez un fichier .afr pour l\'exécuter.');
      return;
    }

    await editor.document.save();
    const filePath = editor.document.uri.fsPath;
    const serverPath = getServerPath();
    const terminal = vscode.window.createTerminal({ name: 'AFRILANG', cwd: path.dirname(filePath) });
    terminal.show();
    terminal.sendText(`"${serverPath}" run "${filePath}"`);
  });
  context.subscriptions.push(disposable);
}

function registerCheckCommand(context) {
  const disposable = vscode.commands.registerCommand('afrilang.checkFile', async () => {
    const editor = vscode.window.activeTextEditor;
    if (!editor || editor.document.languageId !== 'afrilang') {
      vscode.window.showWarningMessage('Ouvrez un fichier .afr pour le vérifier.');
      return;
    }

    await editor.document.save();
    const filePath = editor.document.uri.fsPath;
    const serverPath = getServerPath();
    const terminal = vscode.window.createTerminal({ name: 'AFRILANG', cwd: path.dirname(filePath) });
    terminal.show();
    terminal.sendText(`"${serverPath}" check "${filePath}"`);
  });
  context.subscriptions.push(disposable);
}

function registerRestartCommand(context) {
  const disposable = vscode.commands.registerCommand('afrilang.restartServer', async () => {
    if (!client) return;
    await client.stop();
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
  });
}

function deactivate() {
  if (!client) return undefined;
  return client.stop();
}

module.exports = { activate, deactivate };
