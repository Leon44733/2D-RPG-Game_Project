/**
 * ###############################################################################
 *  File: player_character.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 01.March 2025, 2:47:13 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 01.March 2025, 6:56:02 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include "entities/characters/include/player_character.h"
#include "gfx/render/include/renderer_manager.h"

namespace entities
{
    namespace characters
    {
        PlayerCharacter::PlayerCharacter(int aStartX, int aStartY, int aSpeed, SDL_Texture* aTexture)
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

        void PlayerCharacter::moveUp()
        {
            mPos.y -= mSpeed;
        }

        void PlayerCharacter::moveDown()
        {
            mPos.y += mSpeed;
        }

        void PlayerCharacter::moveLeft()
        {
            mPos.x -= mSpeed;
        }

        void PlayerCharacter::moveRight()
        {
            mPos.x += mSpeed;
        }
    }
}