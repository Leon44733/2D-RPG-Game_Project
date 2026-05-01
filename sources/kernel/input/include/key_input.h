/**
 * ###############################################################################
 *  File: key_input.h
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 22.February 2025, 6:01:49 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 01.May 2026, 8:07:19 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef KEY_INPUT_H
#define KEY_INPUT_H

#include <SDL3/SDL.h>

namespace kernel
{
  namespace input
  {
    /**
     * @brief KeyInput class for handling keyboard input.
     */
    class KeyInput
    {
    public:
      /**
       * @brief Update the keyboard state.
       */
      void update();

      /**
       * @brief Check if a key is pressed.
       * @param aKey SDL_Scancode of the key to check
       * @return true if key is pressed, false otherwise
       */
      bool isKeyPressed(SDL_Scancode aKey) const;

    private:
      const bool* mpState; // pointer to the current keyboard state
    };
  }
}

#endif // KEY_INPUT_H