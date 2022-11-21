add_library(ftensp
	config.cpp
	algorithm.cpp
	zsquare-seed.cpp
	zsquare-param.cpp)
target_link_libraries(ftensp PUBLIC ftcore)