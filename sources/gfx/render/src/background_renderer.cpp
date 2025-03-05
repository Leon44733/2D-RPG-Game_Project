/**
 * ###############################################################################
 *  File: background_renderer.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: We 05.March 2025, 2:28:02 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: We 05.March 2025, 2:47:47 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include "background_renderer.h"

namespace gfx
{
  namespace render
  {
    BackgroundRenderer::BackgroundRenderer(SDL_Renderer* aRenderer) : mRenderer(aRenderer) {}

    void BackgroundRenderer::render(SDL_Texture* aBgTexture, int aOffsetX, int aOffsetY)
    {
      SDL_Rect destRect = {aOffsetX, aOffsetY, 2000, 2000};
      SDL_RenderCopy(mRenderer, aBgTexture, nullptr, &destRect);
    }
  }
}