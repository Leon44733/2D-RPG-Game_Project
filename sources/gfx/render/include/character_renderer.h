/**
 * ###############################################################################
 *  File: character_renderer.h
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 01.March 2025, 3:23:47 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: We 15.October 2025, 10:21:43 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef CHARACTER_RENDERER_H
#define CHARACTER_RENDERER_H

#include <SDL.h>

#include "gfx/render/include/renderable.h"

namespace gfx
{
  namespace render
  {
    /**
     * @brief CharacterRenderer class for rendering character textures.
     */
    class CharacterRenderer
    {
    public:
      /**
       * @brief Construct new CharacterRenderer object.
       * @param aRenderer SDL renderer
       */
      CharacterRenderer(SDL_Renderer* aRenderer);

      /**
       * @brief Destroy CharacterRenderer object.
       */
      ~CharacterRenderer();

      /**
       * @brief Render player character texture at position.
       * @param aCharacter player character to render
       */
      void render(const Renderable& aPlayer);

    private:
      SDL_Renderer* mRenderer; // SDL renderer
    };
  }
}

#endif // CHARACTER_RENDERER_H