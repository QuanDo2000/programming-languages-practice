# Check arguments
if ($args.Length -lt 1) {
  Write-Host "Usage: runWithInput.ps1 <file>"
  Write-Host "The file must be a binary file."
  exit 1
}

$templatePath = Join-Path $PSScriptRoot ".\template.txt" -Resolve

$currentFolder = Get-Location
Write-Host "Current folder: $currentFolder"
$filepath = Join-Path $currentFolder $args[0] -Resolve
$filename = (Get-Item $filepath).BaseName
Write-Host "File path: $filepath"
Write-Host "File name: $filename"

$parentFolder = Split-Path $filepath -Parent
$testFolder = Join-Path $parentFolder "..\test"
if (-not (Test-Path $testFolder)) {
  Write-Host "Test folder not found"
  New-Item -ItemType Directory -Force -Path $testFolder
  $testFolder = Join-Path $parentFolder "..\test" -Resolve
}
Write-Host "Test folder: $testFolder"

$inputFile = Join-Path $parentFolder "..\test\$filename.inp"
if (-not (Test-Path $inputFile)) {
  Write-Host "Input file not found"
  Get-Content $templatePath -Raw | New-Item -ItemType File -Force -Path $inputFile
  $inputFile = Join-Path $parentFolder "..\test\$filename.inp" -Resolve
}
Write-Host "Input file: $inputFile"

$outputFile = Join-Path $parentFolder "..\test\$filename.out"
Get-Content $inputFile -Raw | & $filepath > $outputFile
Write-Host "Output file: $outputFile"
