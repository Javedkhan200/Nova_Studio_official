$ErrorActionPreference = "Stop"
Write-Host "[NovaOS] Initializing Windows Universal Installer..." -ForegroundColor Green

$NovaPath = "$env:USERPROFILE\.nova\bin"
New-Item -ItemType Directory -Force -Path $NovaPath | Out-Null

Write-Host "[NovaOS] Downloading Core Engine for Windows..." -ForegroundColor Cyan
Invoke-WebRequest -Uri "https://raw.githubusercontent.com/Javedkhan200/NovaStudio/main/bin/nova.exe" -OutFile "$NovaPath\nova.exe"

# Inject into PATH
$UserPath = [Environment]::GetEnvironmentVariable("Path", "User")
if ($UserPath -notlike "*$NovaPath*") {
    [Environment]::SetEnvironmentVariable("Path", "$UserPath;$NovaPath", "User")
}

Write-Host "✅ Nova is successfully installed! Restart PowerShell and type 'nova'." -ForegroundColor Green
