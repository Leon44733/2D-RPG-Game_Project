/**
 * ###############################################################################
 *  File: player_character.h
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 01.March 2025, 2:47:03 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Mo 10.March 2025, 1:52:59 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef PLAYER_CHARACTER_H
#define PLAYER_CHARACTER_H

#include "entities/characters/include/character.h"
#include "gfx/render/include/renderer_manager.h"

namespace entities
{
    namespace characters
    {
        /**
         * @brief PlayerCharacter class for rendering the player character.
         * Inherits from Character class.
         */
        class PlayerCharacter : public Character
        {
            public:

                /**
                 * @brief Construct new PlayerCharacter object.
                 */
                PlayerCharacter();

                /**
                 * @brief Construct new PlayerCharacter object.
                 * @param aStartX x-position
                 * @param aStartY y-position
                 * @param aTexture texture
                 */
                PlayerCharacter(int aStartX, int aStartY, SDL_Texture* aTexture);
                
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
                 * @brief ATTENTION: This function is not needed for PlayerCharacter.
                 * @param aRenderer renderer manager
                 * @param aCamera camera
                 */
                void render(gfx::render::RendererManager& aRenderer, std::shared_ptr<gfx::render::ICamera> aCamera) override {};
        };
    }
}

#endif // PLAYER_CHARACTER_H