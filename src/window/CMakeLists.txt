#
################################################################################
# File: CMakeLists.txt
# Project: 2D-RPG-Game
# Created Date: Th 02.January 2025, 2:28:56 pm
# Author: lbarwe
# -----
# Last Modified: Sa 04.January 2025, 1:11:37 pm
# Modified By: lbarwe
# -----
# Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
################################################################################
#

# define a library for the window module
add_library(window STATIC
    src/windowcreator.cpp
    include/windowcreator.h
)

# include directories for this module
target_include_directories(window
    PUBLIC
    ${CMAKE_SOURCE_DIR}/src/window/include
    ${SDL2_INCLUDE_DIRS}
)

# link SDL2 with the window library
target_link_libraries(window SDL2::SDL2)

# link the window library to the main executable
target_link_libraries(mainExecutable window)