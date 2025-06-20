/**
 * ###############################################################################
 *  File: player_character.h
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 01.March 2025, 2:47:03 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: We 18.June 2025, 10:41:59 am
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
         * @brief PlayerCharacter class for the player character.
         * Inherits from class Character.
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
                 * @param aStartX start x-position
                 * @param aStartY start y-position
                 * @param aTexture player texture
                 */
                PlayerCharacter(int aStartX, int aStartY, SDL_Texture* aTexture);
                
                /**
                 * @brief Destroy PlayerCharacter object.
                 * Destroys the player texture.
                 */
                ~PlayerCharacter();

                /**
                 * @brief Render player character.
                 * @param aRenderer renderer manager
                 */
                void render(gfx::render::RendererManager& aRenderer) override;

                /**
                 * @brief ATTENTION: TODO: ist das korrekt? This function is not needed for PlayerCharacter.
                 * @param aRenderer renderer manager
                 * @param aCamera camera
                 */
                [[maybe_unused]] void render([[maybe_unused]] gfx::render::RendererManager& aRenderer, [[maybe_unused]] std::shared_ptr<gfx::render::ICamera> aCamera) override {};
        };
    }
}

#endif // PLAYER_CHARACTER_H