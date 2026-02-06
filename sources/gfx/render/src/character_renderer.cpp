/**
 * ###############################################################################
 *  File: character_renderer.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 01.March 2025, 3:23:58 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 06.February 2026, 9:30:07 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include "gfx/render/include/character_renderer.h"
#include "gfx/render/include/renderable.h"

namespace gfx
{
  namespace render
  {
    CharacterRenderer::CharacterRenderer(SDL_Renderer* apRenderer) : mpRenderer(apRenderer) {}
    CharacterRenderer::~CharacterRenderer() {}

    void CharacterRenderer::render(const Renderable& arPlayer, const std::optional<RenderContext>& /*arCtx*/)
    {
      // get window size
      int window_width, window_height;
      SDL_GetRendererOutputSize(mpRenderer, &window_width, &window_height);

      // center player in window
      int player_x_pos = window_width / 2 - arPlayer.getElementWidth() / 2;
      int player_y_pos = window_height / 2 - arPlayer.getElementHeight() / 2;

      // render texture at position
      SDL_Rect dest_rect = {player_x_pos, player_y_pos, arPlayer.getElementWidth(), arPlayer.getElementHeight()};
      SDL_RenderCopy(mpRenderer, arPlayer.getTexture(), nullptr, &dest_rect);
    }
  }
}