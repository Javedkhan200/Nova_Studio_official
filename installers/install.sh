#!/bin/bash
# Nova Singularity - macOS/Linux/Termux Installer
echo "Installing Nova Singularity Globally..."
if [ -n "$PREFIX" ]; then
    DEST="$PREFIX/bin/nova"
    cp ../bin/nova $DEST
else
    DEST="/usr/local/bin/nova"
    sudo cp ../bin/nova $DEST
fi
chmod +x $DEST
echo -e "\033[1;32mNova installed successfully! Type 'nova' anywhere to begin.\033[0m"
