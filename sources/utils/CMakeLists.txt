#
################################################################################
# File: CMakeLists.txt
# Project: 2D-RPG-Game
# Created Date: Fr 31.January 2025, 8:54:07 pm
# Author: lbarwe
# -----
# Last Modified: Sa 22.February 2025, 12:49:13 pm
# Modified By: lbarwe
# -----
# Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
################################################################################
#

# define library for utils module
add_library(utils STATIC)
target_sources(utils PRIVATE
    src/logger.cpp
)

# include directories for this module
target_include_directories(utils PUBLIC
    ${CMAKE_SOURCE_DIR}/sources
)