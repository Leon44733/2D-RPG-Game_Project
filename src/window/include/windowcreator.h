/**
 * ###############################################################################
 *  File: windowcreator.hh
 *  Project: 2D-RPG-Game
 *  Created Date: Th 02.January 2025, 2:16:29 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 04.January 2025, 1:00:11 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef WINDOWCREATOR_H
#define WINDOWCREATOR_H

#include <SDL2/SDL.h>

namespace Window
{
    class WindowCreator
    {
        public:
            int createWindow();
            void destroyWindow(SDL_Window*);
    };
}

#endif // WINDOWCREATOR_H