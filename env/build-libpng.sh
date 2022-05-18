#!/bin/bash
cd extern/libpng
cmake -S . -B build \
    -DCMAKE_INSTALL_PREFIX=libpng-install \
    -DPNG_SHARED=OFF \
    -DPNG_TESTS=OFF
cmake --build build
cmake --install build