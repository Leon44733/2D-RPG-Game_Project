#
################################################################################
# File: CMakeLists.txt
# Project: 2D-RPG-Game
# Created Date: Mo 17.February 2025, 3:39:51 pm
# Author: lbarwe
# -----
# Last Modified: Tu 18.February 2025, 4:16:29 pm
# Modified By: lbarwe
# -----
# Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
################################################################################
#

# define a library for the gfx module
add_library(gfx STATIC)
target_sources(gfx PRIVATE
    texture/src/texture_manager.cpp
    render/src/renderer_manager.cpp
    render/src/gui_renderer.cpp
)

# include directories for this module
target_include_directories(gfx PUBLIC
    ${CMAKE_SOURCE_DIR}/sources
)

# link SDL2 with the gfx library
target_link_libraries(gfx PRIVATE SDL2::SDL2)