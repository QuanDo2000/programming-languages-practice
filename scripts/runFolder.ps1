$scriptPath = Join-Path $PSScriptRoot ".\runWithInput.ps1" -Resolve

$folder = Resolve-Path $args[0]
Write-Host "Folder: $folder"
Get-ChildItem $folder |
Foreach-Object {
  Write-Host "File: $_"
  $filepath = Join-Path $folder $_ -Resolve | Resolve-Path -Relative
  Start-Process powershell -ArgumentList "& '$scriptPath' '$filepath'" -Wait -NoNewWindow
}
