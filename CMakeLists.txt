#
################################################################################
# File: CMakeLists.txt
# Project: 2D-RPG-Game
# Created Date: Sa 14.December 2024, 12:07:38 am
# Author: lbarwe
# -----
# Last Modified: Fr 01.May 2026, 12:11:06 am
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

# find SDL2 and SDL2_image
if(WIN32)
  set(SDL2_DIR "${CMAKE_SOURCE_DIR}/libs/SDL2/lib/cmake/SDL2")
  set(SDL2_image_DIR "${CMAKE_SOURCE_DIR}/libs/SDL2_image/lib/cmake/SDL2_image")
endif()
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

# add subdirectories
add_subdirectory(sources)