/**
 * ###############################################################################
 *  File: key_input.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 22.February 2025, 6:04:09 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 22.February 2025, 6:05:09 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include "kernel/input/include/key_input.h"

namespace kernel
{
    namespace input
    {
        void KeyInput::update()
        {
            mState = SDL_GetKeyboardState(nullptr);
        }

        bool KeyInput::isKeyPressed(SDL_Scancode aKey) const
        {
            return mState[aKey];
        }
    }
}