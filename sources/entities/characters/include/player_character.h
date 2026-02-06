/**
 * ###############################################################################
 *  File: player_character.h
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 01.March 2025, 2:47:03 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 06.February 2026, 9:15:53 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef PLAYER_CHARACTER_H
#define PLAYER_CHARACTER_H

#include "entities/characters/include/character.h"

namespace gfx::render
{
  // forward declaration
  class RendererManager;
  class ICamera;
}

namespace entities
{
  namespace characters
  {
    /**
     * @brief PlayerCharacter class for the player character.
     *        Inherits from class Character.
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
       * @param apTexture player texture
       */
      PlayerCharacter(int aStartX, int aStartY, SDL_Texture* apTexture);

      /**
       * @brief Destroy PlayerCharacter object.
       *        Destroys the player texture.
       */
      ~PlayerCharacter();

      /**
       * @brief Render player character.
       * @param arRenderer renderer manager
       */
      void render(gfx::render::RendererManager& arRenderer) override;

      /**
       * @brief ATTENTION: TODO: ist das korrekt? This function is not needed for PlayerCharacter.
       * @param arRenderer renderer manager
       * @param apCamera camera
       */
      [[maybe_unused]] void render([[maybe_unused]] gfx::render::RendererManager& arRenderer, [[maybe_unused]] std::shared_ptr<gfx::render::ICamera> apCamera) override {};
    };
  }
}

#endif // PLAYER_CHARACTER_H