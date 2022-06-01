$Env:ROOT_DIR=(Get-Location).Path
$Env:PATH="$Env:ROOT_DIR\out\install\x64-Debug\bin;"+$Env:PATH
$Env:BUILD_TYPE="Debug"