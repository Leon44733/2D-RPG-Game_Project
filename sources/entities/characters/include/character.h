/**
 * ###############################################################################
 *  File: character.h
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 01.March 2025, 2:52:12 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Mo 10.March 2025, 1:50:26 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <SDL.h>

#include "gfx/render/include/renderable.h"

namespace gfx
{
  namespace render
  {
     class RendererManager; // forward declaration
  }
}

namespace entities
{
    namespace characters
    {
        /**
         * @brief Character base class for creating characters.
         */
        class Character : public gfx::render::Renderable
        {
            public:
                /**
                 * Construct new character object.
                 */
                Character();
                
                /**
                 * @brief Construct new character object.
                 * Queries the texture for its width and height.
                 * @param aStartX x-position
                 * @param aStartY y-position
                 * @param aTexture texture
                 */
                Character(int aStartX, int aStartY, SDL_Texture* aTexture);

                /**
                 * @brief Destroy Character object.
                 * Destroys the texture.
                 */
                ~Character();
        };
    }
}

#endif // CHARACTER_H