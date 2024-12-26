#
################################################################################
# File: CMakeLists.txt
# Project: 2D-RPG-Game
# Created Date: Sa 14.December 2024, 12:07:38 am
# Author: lbarwe
# -----
# Last Modified: Th 26.December 2024, 4:27:26 am
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

# define SDL2 path
set(SDL2_DIR "${PROJECT_SOURCE_DIR}/libs/SDL2")

# include and lib directories for SDL2
include_directories(${SDL2_DIR}/include)
link_directories(${SDL2_DIR}/lib)

# add subdirectories
add_subdirectory(src)