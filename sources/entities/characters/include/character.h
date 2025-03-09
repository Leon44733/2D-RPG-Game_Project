/**
 * ###############################################################################
 *  File: character.h
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 01.March 2025, 2:52:12 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Th 06.March 2025, 3:44:09 pm
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
        class Character : public gfx::render::Renderable
        {
            public:
                Character();
                
                /**
                 * @brief Construct new Character object.
                 * Queries the texture for its width and height.
                 * @param aStartX x-position
                 * @param aStartY y-position
                 * @param aSpeed speed
                 * @param aTexture texture
                 */
                Character(int aStartX, int aStartY, int aSpeed, SDL_Texture* aTexture);

                /**
                 * @brief Destroy Character object.
                 * Destroys the texture.
                 */
                ~Character();
                
            protected:
                int mSpeed;     // speed of character
        };
    }
}

#endif // CHARACTER_H