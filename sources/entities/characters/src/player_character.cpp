/**
 * ###############################################################################
 *  File: player_character.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 01.March 2025, 2:47:13 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: We 15.October 2025, 10:22:27 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include "entities/characters/include/player_character.h"

namespace entities
{
  namespace characters
  {
    PlayerCharacter::PlayerCharacter() : Character() {}
    PlayerCharacter::PlayerCharacter(int aStartX, int aStartY, SDL_Texture* aTexture)
        : Character(aStartX, aStartY, aTexture) {}
    PlayerCharacter::~PlayerCharacter() {}

    void PlayerCharacter::render(gfx::render::RendererManager& aRenderer)
    {
      if(mTexture)
      {
        aRenderer.getCharRenderer().render(*this);
      }
    }
  }
}