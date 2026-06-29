#!/bin/bash
echo "[NovaOS] Initializing Universal Installer..."
# Detect OS
if [ -d "$PREFIX" ]; then TARGET="termux"; elif [[ "$OSTYPE" == "linux-gnu"* ]]; then TARGET="linux"; else echo "Use setup.ps1 for Windows."; exit 1; fi

INSTALL_DIR=$HOME/.nova/bin
mkdir -p $INSTALL_DIR

echo "[NovaOS] Downloading Core Engine..."
curl -sSL https://raw.githubusercontent.com/Javedkhan200/NovaStudio/main/bin/nova -o $INSTALL_DIR/nova
chmod +x $INSTALL_DIR/nova

# Inject into PATH
if [ "$TARGET" == "termux" ]; then
    ln -sf $INSTALL_DIR/nova $PREFIX/bin/nova
else
    echo "export PATH=\"$INSTALL_DIR:\$PATH\"" >> ~/.bashrc
fi

echo "✅ Nova is successfully installed! Type 'nova' to start."
