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
Copy-Item -Path "$Env:ROOT_DIR\env\FindZLIB.cmake" -Destination "."
bash -c "git apply ../../env/libpng-changes.patch"
cmake -S . -B build `
    -DCMAKE_INSTALL_PREFIX=libpng-install `
    -DCMAKE_BUILD_TYPE=$Env:BUILD_TYPE `
    -DZLIB_ROOT="$Env:ROOT_DIR\extern\zlib\zlib-install" `
    -DZLIB_USE_STATIC_LIBS=ON `
    -DPNG_SHARED=OFF `
    -DPNG_TESTS=OFF
cmake --build build --config $Env:BUILD_TYPE
cmake --install build --config $Env:BUILD_TYPE

# Go back to root
Set-Location -Path "$Env:ROOT_DIR"