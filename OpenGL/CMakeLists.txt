cmake_minimum_required(VERSION 2.8.12)
PROJECT(Tutorial)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_definitions(-Wall -Wextra -Wshadow -g -pedantic -fPIC -std=c++11)
set(CMAKE_BUILD_TYPE "Debug")

find_package(Bullet REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

find_program(SDL2_CONFIG sdl2-config)
execute_process(COMMAND ${SDL2_CONFIG} "--cflags" OUTPUT_VARIABLE SDL_CFLAGS OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND ${SDL2_CONFIG} "--libs" OUTPUT_VARIABLE SDL_LIBRARIES OUTPUT_STRIP_TRAILING_WHITESPACE)

add_definitions(${SDL_CFLAGS})

include_directories(SYSTEM ${BULLET_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS})

add_executable(Tutorial main.cpp)

target_link_libraries(Tutorial ${SDL_LIBRARIES} ${GLEW_LIBRARIES} ${BULLET_LIBRARIES} ${OPENGL_LIBRARIES})
