#
################################################################################
# File: CMakeLists.txt
# Project: 2D-RPG-Game
# Created Date: Th 26.December 2024, 3:32:33 am
# Author: lbarwe
# -----
# Last Modified: Sa 04.January 2025, 2:11:18 pm
# Modified By: lbarwe
# -----
# Copyright (c) 2024 Leon Barwe - lbarwe.business@gmail.com
################################################################################
#

# define source and header files
set(SOURCES
    main.cpp
)

# define executable
add_executable(mainExecutable ${SOURCES})

# include subdirectory headers
target_include_directories(mainExecutable
    PUBLIC
    ${CMAKE_SOURCE_DIR}/src
)

# add subdirectories
add_subdirectory(window)