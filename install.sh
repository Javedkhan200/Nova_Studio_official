#!/bin/bash
echo "[Nova Installer] Deploying Global Binary..."
DEST="/usr/local/bin/nova"
if [ -n "$PREFIX" ]; then
    DEST="$PREFIX/bin/nova"
fi

if [ -f "bin/nova" ]; then
    cp bin/nova "$DEST"
    chmod +x "$DEST"
    echo -e "\033[1;32m[✔] Nova installed successfully at $DEST\033[0m"
    echo "Run 'nova' to launch the Singularity Engine."
else
    echo -e "\033[1;31m[✖] bin/nova not found. Compile first!\033[0m"
    exit 1
fi
