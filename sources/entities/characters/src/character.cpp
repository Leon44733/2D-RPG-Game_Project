/**
 * ###############################################################################
 *  File: character.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 01.March 2025, 3:01:46 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 01.March 2025, 6:46:21 pm
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
        Character::Character(int aStartX, int aStartY, int aSpeed, SDL_Texture* aTexture)
            : mPos({aStartX, aStartY}), mSpeed(aSpeed), mTexture(aTexture)
        {
            // Query texture for its width and height
            SDL_QueryTexture(mTexture, nullptr, nullptr, &mWidth, &mHeight);
        }

        Character::~Character()
        {
            SDL_DestroyTexture(mTexture);
        }

        int Character::getXPos() const
        {
            return mPos.x;
        }

        int Character::getYPos() const
        {
            return mPos.y;
        }

        int Character::getWidth() const
        {
            return mWidth;
        }

        int Character::getHeight() const
        {
            return mHeight;
        }

        SDL_Texture* Character::getTexture() const
        {
            return mTexture;
        }
    }
}