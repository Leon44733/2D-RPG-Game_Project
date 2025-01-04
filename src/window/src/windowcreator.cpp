/**
 * ###############################################################################
 *  File: windowcreator
 *  Project: 2D-RPG-Game
 *  Created Date: Th 02.January 2025, 2:16:01 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 04.January 2025, 2:05:48 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include <iostream>
#include "windowcreator.h"

namespace Window
{
    int WindowCreator::createWindow()
    {
        // initialize the SDL2 library
        if(SDL_Init(SDL_INIT_VIDEO) != 0)
        {
             // error while trying to initialize
            std::cerr << "SDL2 Error: Failed to initialize the SDL2 library\nSDL Error: " << SDL_GetError() << "\n";
            return -1;
        }

        // create the SDL window
        SDL_Window* window = SDL_CreateWindow(
            "SDL2 Window",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            800,
            600,
            SDL_WINDOW_SHOWN
            );
            
        if(!window)
        {
            // error while trying to create the window
            std::cerr << "SDL2 Error: Failed to create window\nSDL Error: " << SDL_GetError() << "\n";
            SDL_Quit(); // quit SDL if the window could not be created 
            return -1;
        }

        // loop to keep the window open until the X of the window is being pressed
        bool running = true;
        SDL_Event event;
        while(running)
        {
            while(SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    running = false;
                }
            }

            SDL_SetRenderDrawColor(SDL_GetRenderer(window), 0, 0, 225, 225);
            SDL_RenderClear(SDL_GetRenderer(window));
            SDL_RenderPresent(SDL_GetRenderer(window));
        }
        
        destroyWindow(window);
        return 0;
    }

    void WindowCreator::destroyWindow(SDL_Window* window)
    {
        SDL_DestroyWindow(window);  // destroy window
        SDL_Quit(); // quit SDL
    }
}