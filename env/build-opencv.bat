cd extern\opencv
cmake -S . -B build ^
    -DCMAKE_INSTALL_PREFIX=opencv-install ^
    -DOPENCV_FORCE_3RDPARTY_BUILD=ON ^
    -DWITH_EIGEN=OFF ^
    -DBUILD_SHARED_LIBS=OFF ^
    -DCMAKE_FIND_FRAMEWORK=LAST
cmake --build build -j %NUMBER_OF_PROCESSORS%
cmake --install build