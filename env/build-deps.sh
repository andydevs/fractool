#!/bin/bash

# Build boost
echo "Building boost..."
cd $ROOT_DIR/extern/boost
./bootstrap.sh --with-libraries=log,program_options
./b2 --prefix=boost-install link=static install

# Build zlib
echo "Building zlib..."
cd $ROOT_DIR/extern/zlib
cmake -S . -B build \
    -DCMAKE_INSTALL_PREFIX=zlib-install \
    -DCMAKE_BUILD_TYPE=$BUILD_TYPE
cmake --build build --config $BUILD_TYPE
cmake --install build --config $BUILD_TYPE

# Build libpng
echo "Building libpng..."
cd $ROOT_DIR/extern/libpng
cp ../../env/FindZLIB.cmake .
git apply ../../env/libpng-changes.patch
cmake -S . -B build \
    -DCMAKE_INSTALL_PREFIX=libpng-install \
    -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
    -DZLIB_ROOT="$ROOT_DIR/extern/zlib/zlib-install" \
    -DZLIB_USE_STATIC_LIBS=ON \
    -DPNG_SHARED=OFF \
    -DPNG_TESTS=OFF
cmake --build build --config $BUILD_TYPE
cmake --install build --config $BUILD_TYPE

# Go back to root
cd $ROOT_DIR