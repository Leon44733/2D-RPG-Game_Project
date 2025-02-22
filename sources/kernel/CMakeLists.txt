#
################################################################################
# File: CMakeLists.txt
# Project: 2D-RPG-Game
# Created Date: Fr 31.January 2025, 7:34:39 pm
# Author: lbarwe
# -----
# Last Modified: Sa 22.February 2025, 12:50:03 pm
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
target_include_directories(kernel PUBLIC
    ${CMAKE_SOURCE_DIR}/sources
)

# link gfx, ui and SDL2 with kernel library
target_link_libraries(kernel PRIVATE gfx ui SDL2::SDL2)