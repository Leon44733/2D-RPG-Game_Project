#
################################################################################
# File: CMakeLists.txt
# Project: 2D-RPG-Game
# Created Date: Th 02.January 2025, 2:28:56 pm
# Author: lbarwe
# -----
# Last Modified: Su 09.February 2025, 2:10:28 pm
# Modified By: lbarwe
# -----
# Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
################################################################################
#

# define a library for the ui module
add_library(ui STATIC
    src/window.cpp
    src/texture_element.cpp
    src/texture_manager.cpp
    src/renderer_manager.cpp
    src/i_gui_element.cpp
)

# include directories for this module
target_include_directories(ui
    PUBLIC
    ${CMAKE_SOURCE_DIR}
    ${SDL2_INCLUDE_DIRS}
)

# link SDL2 with the ui library
target_link_libraries(ui SDL2::SDL2)

# link the ui library to the main executable
target_link_libraries(mainExecutable ui)