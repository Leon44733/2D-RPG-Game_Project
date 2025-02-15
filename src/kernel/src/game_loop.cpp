/**
 * ###############################################################################
 *  File: game_loop.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 31.January 2025, 7:10:52 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 15.February 2025, 1:28:47 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include <SDL2/SDL.h>
#include <iostream>

#include "src/kernel/include/game_loop.h"
#include "src/ui/include/texture_manager.h"

namespace Kernel
{
    GameLoop::GameLoop(std::shared_ptr<UI::Window> aSDLWindow, std::unique_ptr<UI::GUI::RendererManager> aRendererManager)  :
        mSDLWindow(aSDLWindow), mRendererManager(std::move(aRendererManager))
    {
    }

    GameLoop::~GameLoop()
    {
    }

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
                handleEvents();
            }

            update();
            render();
        }
    }

    void GameLoop::handleEvents()
    {
        // TODO: Handle events for the game
    }

    void GameLoop::update()
    {
        // TODO: Update game logic
    }

    void GameLoop::render()
    {
        mRendererManager->renderAllElements();
    }
}