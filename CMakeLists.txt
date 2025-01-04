#
################################################################################
# File: CMakeLists.txt
# Project: 2D-RPG-Game
# Created Date: Sa 14.December 2024, 12:07:38 am
# Author: lbarwe
# -----
# Last Modified: Sa 04.January 2025, 1:43:00 pm
# Modified By: lbarwe
# -----
# Copyright (c) 2024 Leon Barwe - lbarwe.business@gmail.com
################################################################################
#

# declare minimum cmake version and add a project name
cmake_minimum_required(VERSION 3.16)
project(2D-RPG-Game_Project)

# set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# find SDL2 through cmake
set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/libs/SDL2/lib/cmake/SDL2")
find_package(SDL2 REQUIRED)

# add subdirectories
add_subdirectory(src)