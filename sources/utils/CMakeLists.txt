#
################################################################################
# File: CMakeLists.txt
# Project: 2D-RPG-Game
# Created Date: Fr 31.January 2025, 8:54:07 pm
# Author: lbarwe
# -----
# Last Modified: Tu 18.February 2025, 4:16:53 pm
# Modified By: lbarwe
# -----
# Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
################################################################################
#

# define a library for the utils module
add_library(utils STATIC)
target_sources(utils PRIVATE
    src/logger.cpp
)

# include directories for this module
target_include_directories(utils PUBLIC
    ${CMAKE_SOURCE_DIR}/sources
)