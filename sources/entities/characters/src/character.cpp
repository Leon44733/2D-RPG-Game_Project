/**
 * ###############################################################################
 *  File: character.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 01.March 2025, 3:01:46 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 15.November 2025, 5:01:11 pm
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

      // query texture for its width and height
      SDL_QueryTexture(mpTexture, nullptr, nullptr, &mWidth, &mHeight);
    }

    Character::~Character()
    {
      SDL_DestroyTexture(mpTexture);
    }
  }
}