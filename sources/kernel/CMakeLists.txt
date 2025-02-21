#
################################################################################
# File: CMakeLists.txt
# Project: 2D-RPG-Game
# Created Date: Fr 31.January 2025, 7:34:39 pm
# Author: lbarwe
# -----
# Last Modified: Fr 21.February 2025, 12:18:12 pm
# Modified By: lbarwe
# -----
# Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
################################################################################
#

# define a library for the kernel module
add_library(kernel STATIC)
target_sources(kernel PRIVATE
    src/game_loop.cpp
)

# include directories for this module
target_include_directories(kernel PUBLIC
    ${CMAKE_SOURCE_DIR}/sources
)

# link gfx, ui and SDL2 with the kernel library
target_link_libraries(kernel PRIVATE gfx ui SDL2::SDL2)