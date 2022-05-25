#!/bin/bash

# Build boost
echo "Building boost..."
cd $ROOT_DIR/extern/boost
./bootstrap.sh
./b2 link=static
./b2 install --prefix=boost-install

# Build zlib
echo "Building zlib..."
cd $ROOT_DIR/extern/zlib
cmake -S . -B build -DCMAKE_INSTALL_PREFIX=zlib-install
cmake --build build
cmake --install build

# Build libpng
echo "Building libpng..."
cd $ROOT_DIR/extern/libpng
export ZLIBINC=$ROOT_DIR/extern/zlib/zlib-install/include
export ZLIBLIB=$ROOT_DIR/extern/zlib/zlib-install/lib
export CPPFLAGS="-I$ZLIBINC"
export LDFLAGS="-L$ZLIBLIB"
export LD_LIBRARY_PATH="$ZLIBLIB:$LD_LIBRARY_PATH"
cmake -S . -B build \
    -DPNG_BUILD_ZLIB=ON \
    -DPNG_SHARED=OFF \
    -DPNG_TESTS=OFF \
    -DCMAKE_INSTALL_PREFIX=libpng-install
cmake --build build
cmake --install build