#
################################################################################
# File: CMakeLists.txt
# Project: 2D-RPG-Game
# Created Date: Th 02.January 2025, 2:28:56 pm
# Author: lbarwe
# -----
# Last Modified: Fr 01.May 2026, 6:55:26 pm
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
)

# link gfx, utils, SDL3 and SDL3_image with the ui library
target_link_libraries(ui PRIVATE gfx utils MySDL MySDL_Image)