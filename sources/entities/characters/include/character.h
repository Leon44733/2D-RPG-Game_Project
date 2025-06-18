/**
 * ###############################################################################
 *  File: character.h
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 01.March 2025, 2:52:12 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: We 18.June 2025, 10:42:14 am
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
     class RendererManager; // TODO: Muss diese sein? forward declaration
  }
}

namespace entities
{
    namespace characters
    {
        /**
         * @brief Character base class for creating characters.
         * Inherits from class Renderable.
         */
        class Character : public gfx::render::Renderable
        {
            public:
                /**
                 * @brief Construct new character object.
                 */
                Character();
                
                /**
                 * @brief Construct new character object.
                 * Queries the texture for its width and height.
                 * @param aStartX start x-position
                 * @param aStartY start y-position
                 * @param aTexture character texture
                 */
                Character(int aStartX, int aStartY, SDL_Texture* aTexture);

                /**
                 * @brief Destroy Character object.
                 * Destroys the character texture.
                 */
                ~Character();
        };
    }
}

#endif // CHARACTER_H