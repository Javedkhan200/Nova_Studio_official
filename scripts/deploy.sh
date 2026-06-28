#!/bin/bash
# Automates GitHub commits and Releases
git init
git add .
git commit -m "Nova Singularity Release v1.0"
echo "To publish, run: gh repo create nova-singularity --public --source=. --remote=origin --push"
echo "Then: gh release create v1.0 ./bin/nova ./install.sh -t 'Nova Singularity v1.0' -n 'Official Release'"
