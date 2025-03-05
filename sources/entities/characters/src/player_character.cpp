/**
 * ###############################################################################
 *  File: player_character.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 01.March 2025, 2:47:13 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 01.March 2025, 8:09:28 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include "entities/characters/include/player_character.h"
#include "gfx/render/include/renderer_manager.h"

#include <iostream>

namespace entities
{
    namespace characters
    {
        PlayerCharacter::PlayerCharacter(int aStartX, int aStartY, float aSpeed, SDL_Texture* aTexture)
            : Character(aStartX, aStartY, aSpeed, aTexture) {}
        PlayerCharacter::~PlayerCharacter() {}

        void PlayerCharacter::render(gfx::render::RendererManager& aRenderer)
        {
            // render player character
            if(mTexture)
            {
                aRenderer.getCharacterRenderer().render(this->getTexture(), this->getXPos(), this->getYPos(), this->getWidth(), this->getHeight());
            }
        }

        void PlayerCharacter::moveUp(float aDeltaTime)
        {
            if(aDeltaTime > 0)
            {
                mPos.y -= mSpeed * aDeltaTime;
            }
            std::cout << "Player Position: " << mPos.x << ", " << mPos.y << ", " << mSpeed << ", " << aDeltaTime << std::endl;  // Debugging
        }

        void PlayerCharacter::moveDown(float aDeltaTime)
        {
            mPos.y += mSpeed * aDeltaTime;
        }

        void PlayerCharacter::moveLeft(float aDeltaTime)
        {
            mPos.x -= mSpeed * aDeltaTime;
        }

        void PlayerCharacter::moveRight(float aDeltaTime)
        {
            mPos.x += mSpeed * aDeltaTime;
        }
    }
}