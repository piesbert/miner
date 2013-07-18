project (miner)
cmake_minimum_required (VERSION 2.6)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

subdirs (src)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ansi -Wall -Wextra -pedantic")

find_package(OpenGL REQUIRED)
find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)
find_package(GLEW REQUIRED)

set(SHADERS_PATH "${CMAKE_BINARY_DIR}/src/shaders/")
set(TEXTURES_PATH "${CMAKE_BINARY_DIR}/src/textures/")

message("Shaders: ${SHADERS_PATH}")
message("Textures: ${TEXTURES_PATH}")

