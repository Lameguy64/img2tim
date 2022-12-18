cmake_minimum_required(VERSION 3.0)
project(img2tim LANGUAGES CXX)

find_library(freeimage_lib NAMES FreeImage freeimage)
find_path(freeimage_inc NAMES FreeImage.h freeimage.h)

if(freeimage_lib STREQUAL "freeimage_lib-NOTFOUND" OR
  freeimage_inc STREQUAL "freeimage_inc-NOTFOUND")
  message(FATAL_ERROR "Could not find FreeImage library on your system")
endif()

add_executable(img2tim tim.cpp main.cpp)
target_include_directories(img2tim PUBLIC "${freeimage_inc}" "${PROJECT_SOURCE_DIR}")
target_link_libraries(img2tim "${freeimage_lib}")
