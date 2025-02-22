/**
 * ###############################################################################
 *  File: game_loop.h
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 31.January 2025, 7:11:00 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 22.February 2025, 12:05:26 pm
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
             * @brief Construct a new GameLoop object.
             * 
             * @param aSDLWindow shared pointer to window object
             */
            GameLoop(std::shared_ptr<ui::Window>, std::unique_ptr<gfx::render::RendererManager>);

            /**
             * @brief Destroy the GameLoop object.
             */
            ~GameLoop();
            
            /**
             * @brief Run the game loop.
             */
            void run();

        private:
            std::shared_ptr<ui::Window> mSDLWindow;     // shared pointer to window object
            std::unique_ptr<gfx::render::RendererManager> mRendererManager;

            void handleEvents();
            void update();
            void render();
    };
}

#endif // GAME_LOOP_H