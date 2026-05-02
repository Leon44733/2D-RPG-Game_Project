#
################################################################################
# File: CMakeLists.txt
# Project: 2D-RPG-Game
# Created Date: Fr 31.January 2025, 7:34:39 pm
# Author: lbarwe
# -----
# Last Modified: Sa 02.May 2026, 7:01:46 pm
# Modified By: lbarwe
# -----
# Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
################################################################################
#

# define library for kernel module
add_library(kernel STATIC)
target_sources(kernel PRIVATE
    src/game_loop.cpp
)

# include directories for this module
target_include_directories(kernel PRIVATE
    ${CMAKE_SOURCE_DIR}/sources
)

# link utils and SDL3 with kernel library
target_link_libraries(kernel PRIVATE utils MySDL)