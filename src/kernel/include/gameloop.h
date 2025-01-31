/**
 * ###############################################################################
 *  File: gameloop.h
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 31.January 2025, 7:11:00 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 31.January 2025, 9:20:32 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <memory>

#include "src/ui/include/window.h"

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
            GameLoop(std::shared_ptr<UI::Window>);

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

            // TOOD: Later implement
            // void handleEvents();
            // void update();
            // void render();
    };
}

#endif // GAMELOOP_H