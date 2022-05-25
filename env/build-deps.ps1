# Build boost
echo "Building boost..."
Set-Location -Path "$Env:ROOT_DIR\extern\boost"
& ".\bootstrap.bat"
& ".\b2.exe" "link=static"
& ".\b2.exe" "install" "--prefix=boost-install"

# Build zlib
echo "Building zlib..."
Set-Location -Path "$Env:ROOT_DIR\extern\zlib"
cmake -S . -B build `
    -DCMAKE_INSTALL_PREFIX=zlib-install `
    -DCMAKE_BUILD_TYPE=$Env:BUILD_TYPE
cmake --build build --config $Env:BUILD_TYPE
cmake --install build --config $Env:BUILD_TYPE

# Build libpng
echo "Building libpng..."
Set-Location -Path "$Env:ROOT_DIR\extern\libpng"
cmake -S . -B build `
    -DCMAKE_INSTALL_PREFIX=libpng-install `
    -DCMAKE_BUILD_TYPE=$Env:BUILD_TYPE `
    -DZLIB_ROOT="$Env:ROOT_DIR\extern\zlib\zlib-install" `
    -DPNG_SHARED=OFF `
    -DPNG_TESTS=OFF
cmake --build build --config $Env:BUILD_TYPE
cmake --install build --config $Env:BUILD_TYPE

# Go back to root
Set-Location -Path "$Env:ROOT_DIR"