/**
 * ###############################################################################
 *  File: gui_renderer.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Tu 18.February 2025, 2:12:45 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Mo 10.March 2025, 2:11:02 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include "gfx/render/include/gui_renderer.h"

namespace gfx
{
  namespace render
  {
    GuiRenderer::GuiRenderer(SDL_Renderer* aRenderer) : mRenderer(aRenderer) {}
    GuiRenderer::~GuiRenderer() {}

    void GuiRenderer::render(const Renderable& aElem)
    {
      // render texture at position
      SDL_Rect dstRect = { aElem.getElementPos().x , aElem.getElementPos().y, aElem.getElementWidth(), aElem.getElementHeight() };
      SDL_RenderCopy(mRenderer, aElem.getTexture(), nullptr, &dstRect);
    }
  }
}