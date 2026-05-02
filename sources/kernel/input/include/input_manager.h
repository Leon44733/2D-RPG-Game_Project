/**
 * ###############################################################################
 *  File: input_manager.h
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 02.May 2026, 11:26:25 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Su 03.May 2026, 12:27:26 am
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2026 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <SDL3/SDL.h>

namespace kernel
{
  namespace input
  {
    /**
     * @brief InputManager class for handling user input.
     * This class manages different input types (e.g. keyboard, mouse).
     */
    class InputManager
    {
    public:
      /**
       * @brief Construct new InputManager object.
       */
      InputManager();

      /**
       * @brief Destroy the InputManager object.
       */
      ~InputManager();

      /**
       * @brief Update the input states.
       * This function should be called every frame to update the input states.
       */
      void update();

      /**
       * @brief process a specific key input event.
       * @param aEvent the SDL_Event to process.
       */
      void processEvent(const SDL_Event& aEvent);

    private:
      const bool* mpState; // pointer to the current keyboard state
    };
  }
}

#endif // INPUT_MANAGER_H