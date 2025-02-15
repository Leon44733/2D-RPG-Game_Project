/**
 * ###############################################################################
 *  File: window.h
 *  Project: 2D-RPG-Game
 *  Created Date: Th 02.January 2025, 2:16:29 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 15.February 2025, 12:41:45 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include <memory>

#include "src/ui/include/i_gui_element.h"
#include "src/ui/include/renderer_manager.h"

namespace UI
{
    /**
     * @brief Window class for handling the window.
     */
    class Window
    {
        public:
            /**
             * @brief Construct a new Window object.
             * Default window size is 300x800.
             * Default surface path is empty.
             */
            Window();

            /**
             * @brief Destroy the Window object.
             * This includes destruction of renderer and window.
             */
            ~Window();

            /**
             * @brief Initialize window.
             * This includes initialization of renderer and window.
             */
            bool init();

            /**
             * @brief Destruct window.
             * This includes destruction of renderer and window.
             * Sdl_Quit() is called at the end.
             * This function should be called at the end of the program.
             */
            void destruct();

            void setSize(int, int);                                       // set window size
            SDL_Window* getSDLWindow() const;                             // getter for mSDLWindow

        private:
            SDL_Window* mSDLWindow;                                       // sdl window
            int mWidth;                                                   // window width. Default by constructor is 300
            int mHight;                                                   // window hight. Default by constructor is 800
    };
}

#endif // WINDOW_H