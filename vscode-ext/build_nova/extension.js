const vscode = require('vscode');

function activate(context) {
    let disposable = vscode.commands.registerCommand('nova.run', function () {
        const editor = vscode.window.activeTextEditor;
        if (editor) {
            const document = editor.document;
            const terminal = vscode.window.createTerminal("Nova Engine");
            terminal.show();
            terminal.sendText(`nova "${document.fileName}"`);
        }
    });
    context.subscriptions.push(disposable);
}
exports.activate = activate;
