const { spawn } = require('child_process');
const path = require('path');

let server;

function activate(context) {
  const config = vscode.workspace.getConfiguration('afrilang');
  const serverPath = config.get('serverPath', 'afrilang');

  server = spawn(serverPath, ['lsp'], { stdio: ['pipe', 'pipe', 'pipe'] });

  server.stderr.on('data', (data) => {
    console.error(`AFRILANG LSP: ${data}`);
  });
}

function deactivate() {
  if (server) server.kill();
}

module.exports = { activate, deactivate };
