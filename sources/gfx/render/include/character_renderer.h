/**
 * ###############################################################################
 *  File: character_renderer.h
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 01.March 2025, 3:23:47 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 01.March 2025, 7:35:07 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef CHARACTER_RENDERER_H
#define CHARACTER_RENDERER_H

#include <SDL.h>

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
                 * @brief Render character texture at position.
                 * @param aTexture texture to render
                 * @param x x-position
                 * @param y y-position
                 * @param aWidth texture width
                 * @param aHeight texture height
                 */
                void render(SDL_Texture* aTexture, int x, int y, int aWidth, int aHeight);

            private:
                SDL_Renderer* mRenderer;    // SDL renderer
        };
    }
}

#endif // CHARACTER_RENDERER_H