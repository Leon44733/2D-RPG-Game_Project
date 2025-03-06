/**
 * ###############################################################################
 *  File: character.h
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 01.March 2025, 2:52:12 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Th 06.March 2025, 10:47:27 am
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <SDL.h>

#include "gfx/render/include/i_renderable.h"

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
                
                /**
                 * @brief Get x-position of character.
                 * @return x-position
                 */
                int getXPos() const;

                /**
                 * @brief Get y-position of character.
                 * @return y-position
                 */
                int getYPos() const;

                /**
                 * @brief Get width of character.
                 * @return width
                 */
                int getWidth() const;

                /**
                 * @brief Get height of character.
                 * @return height
                 */
                int getHeight() const;

                /**
                 * @brief Get texture of character.
                 * @return texture
                 */
                SDL_Texture* getTexture() const;
                
            protected:
                SDL_Point mPos;         // position of character
                int mWidth;             // width of character
                int mHeight;            // height of character
                int mSpeed;             // speed of character
                SDL_Texture* mTexture;  // texture of character
        };
    }
}

#endif // CHARACTER_H