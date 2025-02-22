/**
 * ###############################################################################
 *  File: game_loop.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 31.January 2025, 7:10:52 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 22.February 2025, 1:03:00 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include <SDL.h>

#include "kernel/include/game_loop.h"

namespace kernel
{
    GameLoop::GameLoop(std::shared_ptr<ui::Window> aSDLWindow, std::unique_ptr<gfx::render::RendererManager> aRManager)  :
        mSDLWindow(aSDLWindow), mRManager(std::move(aRManager)) {}
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
                handleEvents(); // TODO
            }

            update(); // TODO
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
        mRManager->renderAll();
    }
}