#
################################################################################
# File: CMakeLists.txt
# Project: 2D-RPG-Game
# Created Date: Th 26.December 2024, 3:32:33 am
# Author: lbarwe
# -----
# Last Modified: Th 26.December 2024, 4:05:55 am
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

# link SDL2-libraries
target_link_libraries(mainExecutable SDL2 SDL2main)