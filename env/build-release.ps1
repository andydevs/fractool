cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
Set-Location -Path "build"
cpack
Set-Location -Path ".."