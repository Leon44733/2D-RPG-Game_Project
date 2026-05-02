#
################################################################################
# File: CMakeLists.txt
# Project: 2D-RPG-Game
# Created Date: Th 26.December 2024, 3:32:33 am
# Author: lbarwe
# -----
# Last Modified: Sa 02.May 2026, 11:20:04 pm
# Modified By: lbarwe
# -----
# Copyright (c) 2024 Leon Barwe - lbarwe.business@gmail.com
################################################################################
#

# define executable for the game
add_executable(game
    main.cpp
    game/src/game.cpp
)

# include directories for the main executable
target_include_directories(game PRIVATE
    ${CMAKE_SOURCE_DIR}/sources
)

# link platform and SDL3 with the executable
target_link_libraries(game PRIVATE utils platform kernel MySDL)

# add subdirectories
add_subdirectory(utils)
add_subdirectory(platform)
add_subdirectory(kernel)