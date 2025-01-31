#
################################################################################
# File: CMakeLists.txt
# Project: 2D-RPG-Game
# Created Date: Fr 31.January 2025, 7:34:39 pm
# Author: lbarwe
# -----
# Last Modified: Fr 31.January 2025, 7:37:51 pm
# Modified By: lbarwe
# -----
# Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
################################################################################
#

# define a library for the kernel module
add_library(kernel STATIC
    src/gameloop.cpp
)

# include directories for this module
target_include_directories(kernel
    PUBLIC
    ${CMAKE_SOURCE_DIR}
    ${SDL2_INCLUDE_DIRS}
)

# link SDL2 with the kernel library
target_link_libraries(kernel SDL2::SDL2)

# link the kernel library to the main executable
target_link_libraries(mainExecutable kernel)