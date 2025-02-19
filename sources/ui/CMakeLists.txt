#
################################################################################
# File: CMakeLists.txt
# Project: 2D-RPG-Game
# Created Date: Th 02.January 2025, 2:28:56 pm
# Author: lbarwe
# -----
# Last Modified: Tu 18.February 2025, 4:16:47 pm
# Modified By: lbarwe
# -----
# Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
################################################################################
#

# define a library for the ui module
add_library(ui STATIC)
target_sources(ui PRIVATE
    window/src/window.cpp
    elements/src/texture_element.cpp
)

# include directories for this module
target_include_directories(ui PUBLIC 
    ${CMAKE_SOURCE_DIR}/sources
)

# link gfx and SDL2 with the ui library
target_link_libraries(ui PUBLIC gfx SDL2::SDL2)