cmake_minimum_required(VERSION 3.10)

project(Img2TIM VERSION 1.0)

# Debug
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g -O1")

# C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CXXFLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++20")
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_VERBOSE_MAKEFILE ON)

# PkgConfig
find_package(PkgConfig REQUIRED)

# Mark executable
add_executable(Img2TIM "main.cpp" "tim.cpp")
target_include_directories(Img2TIM PRIVATE "tim.h")

# FreeImage
# find_package(FreeImage CONFIG REQUIRED)
pkg_check_modules(FreeImage REQUIRED IMPORTED_TARGET GLOBAL freeimage)
target_link_libraries(Img2TIM PRIVATE PkgConfig::FreeImage)
