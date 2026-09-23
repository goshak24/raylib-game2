cmake_minimum_required(VERSION 3.20)
project(TheLastMeal CXX C)
set(CMAKE_CXX_STANDARD 17)

# FetchContent to download raylib instead of requiring local install
include(FetchContent)
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/5.0.tar.gz
)
FetchContent_MakeAvailable(raylib)

include_directories(${raylib_SOURCE_DIR}/src src)
file(GLOB_RECURSE SOURCES src/*.cpp src/*.c)
add_executable(TheLastMeal ${SOURCES})
target_link_libraries(TheLastMeal raylib GL m pthread dl rt X11)
