#
################################################################################
# File: CMakeLists.txt
# Project: 2D-RPG-Game
# Created Date: Th 02.January 2025, 2:28:56 pm
# Author: lbarwe
# -----
# Last Modified: Fr 01.May 2026, 12:06:23 am
# Modified By: lbarwe
# -----
# Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
################################################################################
#

# define library for the ui module
add_library(ui STATIC)
target_sources(ui PRIVATE
    window/src/window.cpp
    elements/src/texture_element.cpp
    elements/src/background_element.cpp
)

# include directories for this module
target_include_directories(ui PRIVATE 
    ${CMAKE_SOURCE_DIR}/sources
    ${CMAKE_SOURCE_DIR}/libs/SDL2/include
    ${CMAKE_SOURCE_DIR}/libs/SDL2_image/include
)

# link gfx, utils, SDL2 and SDL2_image with the ui library
target_link_libraries(ui PRIVATE gfx utils SDL2::SDL2 SDL2_image::SDL2_image)