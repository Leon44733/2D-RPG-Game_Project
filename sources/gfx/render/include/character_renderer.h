/**
 * ###############################################################################
 *  File: character_renderer.h
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 01.March 2025, 3:23:47 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 06.February 2026, 8:42:20 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef CHARACTER_RENDERER_H
#define CHARACTER_RENDERER_H

#include <SDL.h>
#include <optional>

#include "gfx/render/include/i_renderer.h"

namespace gfx
{
  namespace render
  {
    /**
     * @brief CharacterRenderer class for rendering character textures.
     */
    class CharacterRenderer : public IRenderer
    {
    public:
      /**
       * @brief Construct new CharacterRenderer object.
       * @param apRenderer SDL renderer
       */
      CharacterRenderer(SDL_Renderer* apRenderer);

      /**
       * @brief Destroy CharacterRenderer object.
       */
      ~CharacterRenderer();

      /**
       * @brief Render player texture at position.
       * @param arPlayer player element to render
       * @param arCtx render context (not used)
       */
      void render(const Renderable& arPlayer, const std::optional<RenderContext>& /*arCtx*/) override;

    private:
      SDL_Renderer* mpRenderer; // SDL renderer
    };
  }
}

#endif // CHARACTER_RENDERER_H