#
################################################################################
# File: CMakeLists.txt
# Project: 2D-RPG-Game
# Created Date: Fr 31.January 2025, 8:54:07 pm
# Author: lbarwe
# -----
# Last Modified: Fr 01.May 2026, 12:01:51 am
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
target_include_directories(utils PRIVATE
    ${CMAKE_SOURCE_DIR}/sources
)