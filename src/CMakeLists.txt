set(SOURCE_FILES
                main.cpp
                config.cpp
                glwindow.cpp
                glscene.cpp
                glcamera.cpp
                glshader.cpp
                glprogram.cpp
                gltexture.cpp
                glcube.cpp
                action.cpp
                actionmanager.cpp
                motionstate.cpp
                )

subdirs(shaders textures)

add_executable(miner ${SOURCE_FILES} )

configure_file(build.h.in ${CMAKE_BINARY_DIR}/config/build.h)

include_directories(${CMAKE_BINARY_DIR}/config/)
include_directories(${OPENGL_INCLUDE_DIRS})

target_link_libraries(miner ${OPENGL_LIBRARIES} ${GLEW_LIBRARY} SDLmain ${SDL_LIBRARY} SDL_image)
