#
################################################################################
# File: CMakeLists.txt
# Project: 2D-RPG-Game
# Created Date: Fr 31.January 2025, 8:54:07 pm
# Author: lbarwe
# -----
# Last Modified: Mo 17.February 2025, 3:50:53 pm
# Modified By: lbarwe
# -----
# Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
################################################################################
#

# define a library for the utils module
add_library(utils STATIC
    src/logger.cpp
)

# include directories for this module
target_include_directories(utils
    PUBLIC
    ${CMAKE_SOURCE_DIR}
    ${SDL2_INCLUDE_DIRS}
)

# link SDL2 with the utils library
target_link_libraries(utils SDL2::SDL2)

# link the utils library to the main executable
target_link_libraries(mainExecutable utils)