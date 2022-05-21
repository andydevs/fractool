#!/bin/bash
echo "Building libpng..."
cd extern/libpng
ZLIBLIB=/path/to/lib export ZLIBLIB
ZLIBINC=/path/to/include export ZLIBINC
CPPFLAGS="-I$ZLIBINC" export CPPFLAGS
LDFLAGS="-L$ZLIBLIB" export LDFLAGS
LD_LIBRARY_PATH="$ZLIBLIB:$LD_LIBRARY_PATH" export LD_LIBRARY_PATH
cmake -S . -B build -DPNG_BUILD_ZLIB=ON -DPNG_SHARED=OFF -DPNG_TESTS=OFF -DCMAKE_INSTALL_PREFIX=libpng-install
cmake --build build
cmake --install build