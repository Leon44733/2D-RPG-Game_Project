#
################################################################################
# File: CMakeLists.txt
# Project: 2D-RPG-Game
# Created Date: Sa 14.December 2024, 12:07:38 am
# Author: lbarwe
# -----
# Last Modified: Fr 01.May 2026, 1:12:53 pm
# Modified By: lbarwe
# -----
# Copyright (c) 2024 Leon Barwe - lbarwe.business@gmail.com
################################################################################
#

# declare minimum cmake version and add a project name
cmake_minimum_required(VERSION 3.16)
project(2D-RPG-Game_Project)

# set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set compiler flags
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -Wall -Wextra -Wpedantic")

# add SDL2 base
add_library(MySDL INTERFACE)
if(WIN32)
    target_include_directories(MySDL INTERFACE
        "${CMAKE_SOURCE_DIR}/libs/SDL2/include"
        "${CMAKE_SOURCE_DIR}/libs/SDL2/include/SDL2"
        )
    target_link_directories(MySDL INTERFACE
        "${CMAKE_SOURCE_DIR}/libs/SDL2/lib"
        )
    target_link_libraries(MySDL INTERFACE "${CMAKE_SOURCE_DIR}/libs/SDL2/lib/libSDL2.dll.a")
else()
    find_package(SDL2 REQUIRED)
    target_link_libraries(MySDL INTERFACE SDL2::SDL2)
endif()

# add SDL2_IMAGE
add_library(MySDL_Image INTERFACE)
if(WIN32)
    target_include_directories(MySDL_Image INTERFACE
        "${CMAKE_SOURCE_DIR}/libs/SDL2_image/include"
        "${CMAKE_SOURCE_DIR}/libs/SDL2_image/include/SDL2"
        )
    target_link_directories(MySDL_Image INTERFACE 
        "${CMAKE_SOURCE_DIR}/libs/SDL2_image/lib"
        )
    target_link_libraries(MySDL_Image INTERFACE "${CMAKE_SOURCE_DIR}/libs/SDL2_image/lib/libSDL2_image.dll.a")
else()
    find_package(SDL2_image REQUIRED)
    target_link_libraries(MySDL_Image INTERFACE SDL2_image::SDL2_image)
endif()

# add subdirectories
add_subdirectory(sources)