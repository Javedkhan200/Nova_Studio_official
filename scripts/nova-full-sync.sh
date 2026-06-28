#!/bin/bash
echo "Syncing with GitHub..."
cd $HOME/NovaStudio
git add .
git commit -m "Emergency Fix: Clean Engine & Math Logic by Architect Javed"
git push origin main
echo "Re-compiling Nova..."
clang++ -std=c++20 src/*.cpp -o bin/nova
echo "Update Successful. Architect: Javed."
