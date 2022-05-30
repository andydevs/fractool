$Env:ROOT_PATH=(Get-Location).Path
$Env:PATH="$Env:ROOT_PATH\out\install\x64-Debug\bin;"+$Env:PATH
$Env:BUILD_TYPE="Debug"