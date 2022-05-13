#!/bin/bash
cd extern/opencv
cmake -S . -B build \
    -DCMAKE_INSTALL_PREFIX=install \
    -DOPENCV_FORCE_3RDPARTY_BUILD=ON \
    -DWITH_EIGEN=OFF \
    -DBUILD_SHARED_LIBS=OFF -DCMAKE_FIND_FRAMEWORK=LAST
cmake --build build -j6
cmake --install build