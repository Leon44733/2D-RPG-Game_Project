#
################################################################################
# File: CMakeLists.txt
# Project: 2D-RPG-Game
# Created Date: Sa 02.May 2026, 4:35:59 pm
# Author: lbarwe
# -----
# Last Modified: Sa 02.May 2026, 4:40:22 pm
# Modified By: lbarwe
# -----
# Copyright (c) 2026 Leon Barwe - lbarwe.business@gmail.com
################################################################################
#

# define library for platform module
add_library(platform STATIC)
target_sources(platform PRIVATE
    src/sdl_context.cpp
    src/window.cpp
)

# include directories for this module
target_include_directories(platform PRIVATE
    ${CMAKE_SOURCE_DIR}/sources
)

# link utils and SDL3 with platform library
target_link_libraries(platform PRIVATE utils MySDL)