#
################################################################################
# File: CMakeLists.txt
# Project: 2D-RPG-Game
# Created Date: Mo 17.February 2025, 3:39:51 pm
# Author: lbarwe
# -----
# Last Modified: Fr 01.May 2026, 6:55:26 pm
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
target_include_directories(gfx PRIVATE
    ${CMAKE_SOURCE_DIR}/sources
)

# link SDL3 and SDL3_image with the gfx library
target_link_libraries(gfx PRIVATE MySDL MySDL_Image)