#
################################################################################
# File: CMakeLists.txt
# Project: 2D-RPG-Game
# Created Date: Th 26.December 2024, 3:32:33 am
# Author: lbarwe
# -----
# Last Modified: Sa 01.March 2025, 7:00:39 pm
# Modified By: lbarwe
# -----
# Copyright (c) 2024 Leon Barwe - lbarwe.business@gmail.com
################################################################################
#

# define executable for the game
add_executable(game main.cpp)

# include directories for the main executable
target_include_directories(game PUBLIC
    ${CMAKE_SOURCE_DIR}/sources
)

# link ui, gfx, entities, kernel, utils and SDL2 with the executable
target_link_libraries(game PRIVATE ui gfx entities kernel utils SDL2::SDL2)

# add subdirectories
add_subdirectory(ui)
add_subdirectory(gfx)
add_subdirectory(kernel)
add_subdirectory(utils)
add_subdirectory(entities)
# add_subdirectory(persistence)