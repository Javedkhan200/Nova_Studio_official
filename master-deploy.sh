#!/bin/bash
echo "🚀 [Master Architect Mode] Initiating Global Deployment..."

# 1. Compile C++ Engine
echo "⚙️ Compiling Nova C++ Engine..."
clang++ -std=c++20 -O3 -pthread $HOME/NovaStudio/src/main.cpp -o $HOME/NovaStudio/bin/nova

# 2. Pack VS Code Extension
echo "📦 Packing VS Code VSIX..."
cd $HOME/NovaStudio/vscode-ext
python pack_vsix.py
cd $HOME/NovaStudio

# 3. GitHub Push
echo "🌐 Pushing to Global Repository..."
git add .
git commit -m "Automated Deployment - AI, Game & App Ecosystem Live"
git push -u origin main

echo "✅ Deployment Complete! Website and Installers are now LIVE."
