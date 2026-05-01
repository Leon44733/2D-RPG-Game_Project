#
################################################################################
# File: CMakeLists.txt
# Project: 2D-RPG-Game
# Created Date: Sa 14.December 2024, 12:07:38 am
# Author: lbarwe
# -----
# Last Modified: Fr 01.May 2026, 7:00:05 pm
# Modified By: lbarwe
# -----
# Copyright (c) 2024 Leon Barwe - lbarwe.business@gmail.com
################################################################################
#

# declare minimum cmake version and add a project name
cmake_minimum_required(VERSION 4.0.0)
project(2D-RPG-Game_Project)

# set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set compiler flags
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -Wall -Wextra -Wpedantic")

# add SDL3 base
add_library(MySDL INTERFACE)
if(WIN32)
    target_include_directories(MySDL INTERFACE
        "${CMAKE_SOURCE_DIR}/libs/SDL3/include"
        "${CMAKE_SOURCE_DIR}/libs/SDL3/include/SDL3"
        )
    target_link_directories(MySDL INTERFACE
        "${CMAKE_SOURCE_DIR}/libs/SDL3/lib"
        )
    target_link_libraries(MySDL INTERFACE "${CMAKE_SOURCE_DIR}/libs/SDL3/lib/libSDL3.dll.a")
else()
    find_package(SDL3 REQUIRED)
    target_link_libraries(MySDL INTERFACE SDL3::SDL3)
endif()

# add SDL3_IMAGE
add_library(MySDL_Image INTERFACE)
if(WIN32)
    target_include_directories(MySDL_Image INTERFACE
        "${CMAKE_SOURCE_DIR}/libs/SDL3_image/include"
        "${CMAKE_SOURCE_DIR}/libs/SDL3_image/include/SDL3"
        )
    target_link_directories(MySDL_Image INTERFACE 
        "${CMAKE_SOURCE_DIR}/libs/SDL3_image/lib"
        )
    target_link_libraries(MySDL_Image INTERFACE "${CMAKE_SOURCE_DIR}/libs/SDL3_image/lib/libSDL3_image.dll.a")
else()
    find_package(SDL3_image REQUIRED)
    target_link_libraries(MySDL_Image INTERFACE SDL3_image::SDL3_image)
endif()

# add subdirectories
add_subdirectory(sources)