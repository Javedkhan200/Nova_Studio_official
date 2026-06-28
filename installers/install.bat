@echo off
echo Installing Nova Singularity Engine (Commercial Edition)...
set NOVA_PATH=%~dp0..\bin
setx PATH "%PATH%;%NOVA_PATH%" /M
echo Nova installed successfully! Please restart your terminal.
pause
