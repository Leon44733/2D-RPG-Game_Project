/**
 * ###############################################################################
 *  File: game_loop.h
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 31.January 2025, 7:11:00 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 15.February 2025, 12:17:38 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include <memory>

#include "src/ui/include/window.h"
#include "src/ui/include/renderer_manager.h"

namespace Kernel
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
            GameLoop(std::shared_ptr<UI::Window>, std::unique_ptr<UI::GUI::RendererManager>);

            /**
             * @brief Destroy the GameLoop object.
             */
            ~GameLoop();
            
            /**
             * @brief Run the game loop.
             */
            void run();

        private:
            std::shared_ptr<UI::Window> mSDLWindow;     // shared pointer to window object
            std::unique_ptr<UI::GUI::RendererManager> mRendererManager;

            void handleEvents();
            void update();
            void render();
    };
}

#endif // GAME_LOOP_H