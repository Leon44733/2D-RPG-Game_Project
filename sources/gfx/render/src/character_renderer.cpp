/**
 * ###############################################################################
 *  File: character_renderer.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 01.March 2025, 3:23:58 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 01.March 2025, 7:37:10 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include "gfx/render/include/character_renderer.h"

namespace gfx
{
    namespace render
    {
        CharacterRenderer::CharacterRenderer(SDL_Renderer* aRenderer): mRenderer(aRenderer) {}
        CharacterRenderer::~CharacterRenderer() {}

        void CharacterRenderer::render(SDL_Texture* aTexture, int x, int y, int aWidth, int aHeight)
        {
            SDL_Rect destRect = {x, y, aWidth, aHeight};
            SDL_RenderCopy(mRenderer, aTexture, nullptr, &destRect);
        }
    }
}