project (miner)
cmake_minimum_required (VERSION 2.6)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

subdirs (src)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ansi -Wall -pedantic")

find_package(OpenGL REQUIRED)
find_package(SDL REQUIRED)
find_package(GLEW REQUIRED)
