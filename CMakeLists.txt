cmake_minimum_required(VERSION 2.8)
PROJECT( ruzzle_math )
ADD_EXECUTABLE( ruzzle_math backtrack.cpp paths.cpp graph.cpp)
SET(CMAKE_CXX_FLAGS "-std=c++0x")
