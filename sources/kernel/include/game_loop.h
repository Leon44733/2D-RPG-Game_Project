/**
 * ###############################################################################
 *  File: game_loop.h
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 31.January 2025, 7:11:00 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 22.February 2025, 1:02:41 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include <memory>

#include "ui/window/include/window.h"
#include "gfx/render/include/renderer_manager.h"

namespace kernel
{
    /**
     * @brief GameLoop class for handling the game loop.
     */
    class GameLoop
    {
        public:
            /**
             * @brief Construct new GameLoop object.
             * @param aSDLWindow shared pointer to window object
             * @param aRManager unique pointer to renderer manager object
             */
            GameLoop(std::shared_ptr<ui::Window> aSDLWindow, std::unique_ptr<gfx::render::RendererManager> aRManager);

            /**
             * @brief Destroy GameLoop object.
             */
            ~GameLoop();
            
            /**
             * @brief Run the game loop.
             * This function handles events, updates game logic and renders the game.
             */
            void run();

        private:
            /**
             * @brief Handle events for the game.
             */
            void handleEvents(); //TODO
            
            /**
             * @brief Update game logic.
             */
            void update(); //TODO
            
            /**
             * @brief Render the game.
             * This function renders all elements of the game.
             */
            void render();
            
            std::shared_ptr<ui::Window> mSDLWindow;                      // shared pointer to window object
            std::unique_ptr<gfx::render::RendererManager> mRManager;     // unique pointer to renderer manager object
    };
}

#endif // GAME_LOOP_H