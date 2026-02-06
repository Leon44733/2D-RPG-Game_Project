/**
 * ###############################################################################
 *  File: player_character.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 01.March 2025, 2:47:13 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 06.February 2026, 9:03:24 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include "entities/characters/include/player_character.h"

#include "gfx/render/include/renderer_manager.h"
#include "gfx/render/include/i_renderer.h"

namespace entities
{
  namespace characters
  {
    PlayerCharacter::PlayerCharacter() : Character() {}
    PlayerCharacter::PlayerCharacter(int aStartX, int aStartY, SDL_Texture* apTexture)
        : Character(aStartX, aStartY, apTexture) {}
    PlayerCharacter::~PlayerCharacter() {}

    void PlayerCharacter::render(gfx::render::RendererManager& arRenderer)
    {
      if(mpTexture)
      {
        arRenderer.getCharRenderer().render(*this, std::nullopt);
      }
    }
  }
}