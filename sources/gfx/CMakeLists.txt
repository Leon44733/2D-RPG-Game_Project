#
################################################################################
# File: CMakeLists.txt
# Project: 2D-RPG-Game
# Created Date: Mo 17.February 2025, 3:39:51 pm
# Author: lbarwe
# -----
# Last Modified: Sa 15.November 2025, 12:03:16 am
# Modified By: lbarwe
# -----
# Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
################################################################################
#

# define library for gfx module
add_library(gfx STATIC)
target_sources(gfx PRIVATE
    render/src/background_renderer.cpp
    render/src/character_renderer.cpp
    render/src/gui_renderer.cpp
    render/src/renderer_factory.cpp
    render/src/renderer_manager.cpp
    texture/src/texture_manager.cpp
)

# include directories for this module
target_include_directories(gfx PUBLIC
    ${CMAKE_SOURCE_DIR}/sources
)

# link SDL2 and SDL2_image with the gfx library
target_link_libraries(gfx PRIVATE SDL2::SDL2 SDL2_image::SDL2_image)