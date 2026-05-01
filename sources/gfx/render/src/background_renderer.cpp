/**
 * ###############################################################################
 *  File: background_renderer.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: We 05.March 2025, 2:28:02 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 01.May 2026, 7:45:44 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include "gfx/render/include/background_renderer.h"
#include "gfx/render/include/renderable.h"
#include "gfx/render/include/i_camera.h"

namespace gfx
{
  namespace render
  {
    BackgroundRenderer::BackgroundRenderer(SDL_Renderer* apRenderer) : mpRenderer(apRenderer) {}
    BackgroundRenderer::~BackgroundRenderer() {}

    void BackgroundRenderer::render(const Renderable& arElem, const std::optional<RenderContext>& arCtx)
    {
      float bg_pos_x = 0.f;
      float bg_pos_y = 0.f;

      // adjust background position based on camera position if camera is provided
      if (arCtx && arCtx->mpCamera)
      {
        bg_pos_x = 0 - arCtx->mpCamera->getPos().x;
        bg_pos_y = 0 - arCtx->mpCamera->getPos().y;
      }

      // render texture at position
      SDL_FRect dest_rect = {bg_pos_x, bg_pos_y, arElem.getElementWidth(), arElem.getElementHeight()};
      SDL_RenderTexture(mpRenderer, arElem.getTexture(), nullptr, &dest_rect);
    }
  }
}