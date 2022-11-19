add_library(ftensp
	algorithm.cpp
	generate_julia.cpp
	generate_mandelbrot.cpp)
target_link_libraries(ftensp PUBLIC ftcore)