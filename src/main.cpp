/**
 * ###############################################################################
 *  File: main.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Th 26.December 2024, 3:25:20 am
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 04.January 2025, 2:11:51 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2024 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL2/SDL.h>
#include "window/include/windowcreator.h"

int main(int argc, char* argv[]) 
{
    std::cout << "Hello World!" << std::endl;

    Window::WindowCreator window;
    window.createWindow();

    return 0;
}