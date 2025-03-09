/**
 * ###############################################################################
 *  File: player_character.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 01.March 2025, 2:47:13 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 08.March 2025, 6:36:18 pm
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
        PlayerCharacter::PlayerCharacter(int aStartX, int aStartY, int aSpeed, SDL_Texture* aTexture)
            : Character(aStartX, aStartY, aSpeed, aTexture) {}
        PlayerCharacter::~PlayerCharacter() {}

        void PlayerCharacter::render(gfx::render::RendererManager& aRenderer, std::shared_ptr<gfx::render::ICamera> aCamera)
        {
            if(mTexture)
            {
                aRenderer.getCharRenderer().render(*this, aCamera);
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