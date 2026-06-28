#!/bin/bash
echo "Updating Nova Singularity..."
cd $HOME/NovaStudio
git pull origin main
clang++ -std=c++20 src/*.cpp -o bin/nova -lcurl
echo "Nova Updated successfully. Architect: Javed."
