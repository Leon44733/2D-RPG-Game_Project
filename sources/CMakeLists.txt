#
################################################################################
# File: CMakeLists.txt
# Project: 2D-RPG-Game
# Created Date: Th 26.December 2024, 3:32:33 am
# Author: lbarwe
# -----
# Last Modified: Mo 17.February 2025, 3:46:01 pm
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
    ${CMAKE_SOURCE_DIR}/sources
)

# add subdirectories
add_subdirectory(ui)
add_subdirectory(gfx)
add_subdirectory(kernel)
add_subdirectory(utils)
# add_subdirectory(persistence)
# add_subdirectory(character_control)