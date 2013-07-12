set(SOURCE_FILES
                main.cpp
                config.cpp
                glwindow.cpp
                glscene.cpp
                glcamera.cpp
                action.cpp
                actionmanager.cpp
                motionstate.cpp
                )

add_executable(miner ${SOURCE_FILES} )

configure_file(build.h.in ${CMAKE_BINARY_DIR}/config/build.h)

include_directories(${CMAKE_BINARY_DIR}/config/)
include_directories(${OPENGL_INCLUDE_DIRS})

target_link_libraries(miner ${OPENGL_LIBRARIES} SDLmain ${SDL_LIBRARY})
