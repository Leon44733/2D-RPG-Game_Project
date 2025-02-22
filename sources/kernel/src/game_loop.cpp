/**
 * ###############################################################################
 *  File: game_loop.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 31.January 2025, 7:10:52 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 22.February 2025, 6:48:09 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include <SDL.h>
#include <iostream>

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

            update();
            render();
        }
    }

    void GameLoop::render()
    {
        mRManager->renderAll();
    }

    void GameLoop::update()
    {
        // update key input
        mKeyInput.update();
        checkForInput();
    }
    
    void GameLoop::handleEvents()
    {
        // TODO: Handle events for the game
        // for example: on key press, on mouse click, etc. for starting a menu etc.
    }

    void GameLoop::checkForInput() // TODO
    {
        if (mKeyInput.isKeyPressed(SDL_SCANCODE_W)) { /* nach oben bewegen */ }
        if (mKeyInput.isKeyPressed(SDL_SCANCODE_A)) { /* nach links bewegen */ }
        if (mKeyInput.isKeyPressed(SDL_SCANCODE_S)) { /* nach unten bewegen */ }
        if (mKeyInput.isKeyPressed(SDL_SCANCODE_D)) { /* nach rechts bewegen */ }
    }
}