/**
 * ###############################################################################
 *  File: background_renderer.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: We 05.March 2025, 2:28:02 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 15.November 2025, 12:16:25 am
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include "gfx/render/include/background_renderer.h"

namespace gfx
{
  namespace render
  {
    BackgroundRenderer::BackgroundRenderer(SDL_Renderer* aRenderer) : mRenderer(aRenderer) {}
    BackgroundRenderer::~BackgroundRenderer() {}

    void BackgroundRenderer::render(const Renderable& aElem, const std::optional<RenderContext>& aCtx)
    {
      int bg_pos_x = 0;
      int bg_pos_y = 0;

      // adjust background position based on camera position if camera is provided
      if (aCtx && aCtx->camera)
      {
        bg_pos_x = 0 - aCtx->camera->getPos().x;
        bg_pos_y = 0 - aCtx->camera->getPos().y;
      }

      // render texture at position
      SDL_Rect destRect = {bg_pos_x, bg_pos_y, aElem.getElementWidth(), aElem.getElementHeight()};
      SDL_RenderCopy(mRenderer, aElem.getTexture(), nullptr, &destRect);
    }
  }
}