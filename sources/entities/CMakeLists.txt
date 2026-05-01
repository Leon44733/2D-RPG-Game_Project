#
################################################################################
# File: CMakeLists.txt
# Project: 2D-RPG-Game
# Created Date: Sa 01.March 2025, 3:02:36 pm
# Author: lbarwe
# -----
# Last Modified: Fr 01.May 2026, 6:55:26 pm
# Modified By: lbarwe
# -----
# Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
################################################################################
#

# define library for entities module
add_library(entities STATIC)
target_sources(entities PRIVATE
    characters/src/character.cpp
    characters/src/player_character.cpp
)

# include directories for this module
target_include_directories(entities PRIVATE
    ${CMAKE_SOURCE_DIR}/sources
)

# link gfx and SDL3 with entities library
target_link_libraries(entities PRIVATE gfx MySDL)