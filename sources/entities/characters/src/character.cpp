/**
 * ###############################################################################
 *  File: character.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 01.March 2025, 3:01:46 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 01.May 2026, 8:05:21 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include "entities/characters/include/character.h"

namespace entities
{
  namespace characters
  {
    Character::Character() {}
    Character::Character(int aStartX, int aStartY, SDL_Texture* apTexture)
    {
      mPos.x = aStartX;
      mPos.y = aStartY;
      mpTexture = apTexture;

      // Query texture for its width and height
      float w, h = 0.f;
      SDL_GetTextureSize(mpTexture, &w, &h);
      mWidth = w;
      mHeight = h;
    }

    Character::~Character()
    {
      SDL_DestroyTexture(mpTexture);
    }
  }
}