/**
 * ###############################################################################
 *  File: gameloop.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 31.January 2025, 7:10:52 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 31.January 2025, 9:30:59 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include <SDL2/SDL.h>
#include <iostream>

#include "src/kernel/include/gameloop.h"
#include "src/utils/include/Logger.h"

namespace Kernel
{
    GameLoop::GameLoop(std::shared_ptr<UI::Window> aSDLWindow)  : mSDLWindow(aSDLWindow) {}

    GameLoop::~GameLoop() {}

    void GameLoop::run()
    {
        bool running = true;
        SDL_Event event;

        while (running)
        {
            // open window until user closes it
            while (SDL_PollEvent(&event))
            {
                // check if user closes window
                if (event.type == SDL_QUIT)
                {
                    running = false;
                }

                // check if surface image exists
                if (!mSDLWindow->getSurfacePath().empty())
                {
                    // load splash image
                    SDL_Surface* surface = SDL_LoadBMP(mSDLWindow->getSurfacePath().c_str());
                    if (surface == nullptr)
                    {
                        Utils::LOG::Logger::error("Unable to load image: " + mSDLWindow->getSurfacePath());
                    }
                    else
                    {
                        // render image
                        SDL_BlitSurface(surface, nullptr, SDL_GetWindowSurface(mSDLWindow->getSDLWindow()), nullptr);
                        SDL_UpdateWindowSurface(mSDLWindow->getSDLWindow());
                        SDL_FreeSurface(surface);
                    }
                }
            }
        }
        // destruct window
        mSDLWindow->destruct();
    }
}