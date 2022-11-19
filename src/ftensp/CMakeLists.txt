add_library(ftensp
	algorithm.cpp
	zsquare-seed.cpp
	zsquare-param.cpp)
target_link_libraries(ftensp PUBLIC ftcore)