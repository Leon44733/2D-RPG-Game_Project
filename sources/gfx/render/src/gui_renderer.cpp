/**
 * ###############################################################################
 *  File: gui_renderer.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Tu 18.February 2025, 2:12:45 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 01.May 2026, 7:48:52 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include "gfx/render/include/gui_renderer.h"
#include "gfx/render/include/renderable.h"

namespace gfx
{
  namespace render
  {
    GuiRenderer::GuiRenderer(SDL_Renderer* apRenderer) : mpRenderer(apRenderer) {}
    GuiRenderer::~GuiRenderer() {}

    void GuiRenderer::render(const Renderable& arElem, const std::optional<RenderContext>& /*arCtx*/)
    {
      // render texture at position
      SDL_FRect dest_rect = {arElem.getElementPos().x, arElem.getElementPos().y, arElem.getElementWidth(), arElem.getElementHeight()};
      SDL_RenderTexture(mpRenderer, arElem.getTexture(), nullptr, &dest_rect);
    }
  }
}