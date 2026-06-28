#!/bin/bash
# Note: Requires Node.js and vsce (npm install -g @vscode/vsce)
cd "$(dirname "$0")"
npm install vscode
vsce package
