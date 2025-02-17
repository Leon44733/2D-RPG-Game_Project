#
################################################################################
# File: CMakeLists.txt
# Project: 2D-RPG-Game
# Created Date: Mo 17.February 2025, 3:39:51 pm
# Author: lbarwe
# -----
# Last Modified: Mo 17.February 2025, 3:41:07 pm
# Modified By: lbarwe
# -----
# Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
################################################################################
#

# define a library for the gfx module
add_library(gfx STATIC
    renderer/src/renderer_manager.cpp
    texture/src/texture_manager.cpp
)

# include directories for this module
target_include_directories(gfx
    PUBLIC
    ${CMAKE_SOURCE_DIR}
    ${SDL2_INCLUDE_DIRS}
)

# link SDL2 with the gfx library
target_link_libraries(gfx SDL2::SDL2)

# link the gfx library to the main executable
target_link_libraries(mainExecutable gfx)