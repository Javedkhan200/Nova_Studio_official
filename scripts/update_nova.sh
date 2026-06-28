#!/bin/bash
echo -e "\033[1;36m[Nova Singularity] Global Update Initiated...\033[0m"

# Git Pull (अगर गिटहब पर अपडेट्स हैं)
cd $HOME/NovaStudio
echo "[*] Pulling latest updates from GitHub..."
git pull origin main || echo "[!] No remote repo found, skipping..."

# Re-compilation (इंजन को फिर से तरोताजा करना)
echo "[*] Re-compiling Singularity Core..."
clang++ -std=c++20 src/*.cpp -o bin/nova -lcurl

# Global Path Update (ताकि कमांड हर जगह काम करे)
echo "[*] Updating Global Binary..."
if [ -d "/data/data/com.termux/files/usr/bin" ]; then
    cp bin/nova $PREFIX/bin/nova
    chmod +x $PREFIX/bin/nova
fi

echo -e "\033[1;32m[✔] Nova Ecosystem Updated Successfully! Architect: Javed\033[0m"
