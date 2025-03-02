/**
 * ###############################################################################
 *  File: player_character.h
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 01.March 2025, 2:47:03 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 01.March 2025, 6:55:28 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef PLAYER_CHARACTER_H
#define PLAYER_CHARACTER_H

#include "entities/characters/include/character.h"

namespace entities
{
    namespace characters
    {
        /**
         * @brief PlayerCharacter class for rendering the player character.
         * Inherits from Character class.
         * Provides functions for moving the player character.
         */
        class PlayerCharacter : public Character
        {
            public:
                /**
                 * @brief Construct new PlayerCharacter object.
                 * @param aStartX x-position
                 * @param aStartY y-position
                 * @param aSpeed speed
                 * @param aTexture texture
                 */
                PlayerCharacter(int aStartX, int aStartY, int aSpeed, SDL_Texture* aTexture);
                
                /**
                 * @brief Destroy PlayerCharacter object.
                 * Destroys the texture.
                 */
                ~PlayerCharacter();

                /**
                 * @brief Render player character.
                 * @param aRenderer renderer manager
                 */
                void render(gfx::render::RendererManager& aRenderer) override;

                /**
                 * @brief Update player character.
                 * TODO: This function is not implemented yet.
                 */
                void update() override {};

                /**
                 * @brief Move player character up.
                 * Decreases y-position by speed.
                 */
                void moveUp();

                /**
                 * @brief Move player character down.
                 * Increases y-position by speed.
                 */
                void moveDown();

                /**
                 * @brief Move player character left.
                 * Decreases x-position by speed.
                 */
                void moveLeft();

                /**
                 * @brief Move player character right.
                 * Increases x-position by speed.
                 */
                void moveRight();
        };
    }
}

#endif // PLAYER_CHARACTER_H