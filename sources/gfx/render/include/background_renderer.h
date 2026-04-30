/**
 * ###############################################################################
 *  File: background_renderer.h
 *  Project: 2D-RPG-Game
 *  Created Date: We 05.March 2025, 2:26:54 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Th 30.April 2026, 10:34:13 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef BACKGROUND_RENDERER_H
#define BACKGROUND_RENDERER_H

#include <SDL2/SDL.h>
#include <optional>

#include "gfx/render/include/i_renderer.h"

namespace gfx
{
  namespace render
  {
    /**
     * @brief BackgroundRenderer class for rendering background textures.
     *        Inherits from class IRenderer.
     */
    class BackgroundRenderer : public IRenderer
    {
    public:
      /**
       * @brief Construct new BackgroundRenderer object.
       * @param apRenderer SDL renderer
       */
      BackgroundRenderer(SDL_Renderer* apRenderer);

      /**
       * @brief Destroy BackgroundRenderer object.
       */
      ~BackgroundRenderer();

      /**
       * @brief Render background texture at position defined by camera.
       * @param arElem background element to render
       * @param arCtx render context containing camera information
       */
      void render(const Renderable& arElem, const std::optional<RenderContext>& arCtx) override;

    private:
      SDL_Renderer* mpRenderer; // SDL Renderer
    };
  }
}

#endif // BACKGROUND_RENDERER_H