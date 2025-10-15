/**
 * ###############################################################################
 *  File: character_renderer.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 01.March 2025, 3:23:58 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: We 15.October 2025, 10:13:12 pm
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
    CharacterRenderer::CharacterRenderer(SDL_Renderer* aRenderer) : mRenderer(aRenderer) {}
    CharacterRenderer::~CharacterRenderer() {}

    void CharacterRenderer::render(const Renderable& aPlayer)
    {
      int windowWidth, windowHeight;
      SDL_GetRendererOutputSize(mRenderer, &windowWidth, &windowHeight);
      int playerPosX = windowWidth / 2 - aPlayer.getElementWidth() / 2;
      int playerPosY = windowHeight / 2 - aPlayer.getElementHeight() / 2;

      // render texture at position
      SDL_Rect destRect = {playerPosX, playerPosY, aPlayer.getElementWidth(), aPlayer.getElementHeight()};
      SDL_RenderCopy(mRenderer, aPlayer.getTexture(), nullptr, &destRect);
    }
  }
}