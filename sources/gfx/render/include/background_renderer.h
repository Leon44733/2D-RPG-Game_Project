/**
 * ###############################################################################
 *  File: background_renderer.h
 *  Project: 2D-RPG-Game
 *  Created Date: We 05.March 2025, 2:26:54 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 14.November 2025, 11:45:33 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef BACKGROUND_RENDERER_H
#define BACKGROUND_RENDERER_H

#include <SDL.h>

#include "gfx/render/include/i_renderer.h"

namespace gfx
{
  namespace render
  {
    /**
     * @brief BackgroundRenderer class for rendering background textures.
     */
    class BackgroundRenderer : public IRenderer
    {
    public:
      /**
       * @brief Construct new BackgroundRenderer object.
       * @param aRenderer SDL renderer
       */
      BackgroundRenderer(SDL_Renderer* aRenderer);

      /**
       * @brief Destroy BackgroundRenderer object.
       */
      ~BackgroundRenderer();

      /**
       * @brief Render background texture at position defined by camera.
       * @param aElem background element to render
       * @param aCamera camera
       */
      void render(const Renderable& aElem, const std::optional<RenderContext>& aCtx) override;

    private:
      SDL_Renderer* mRenderer; // SDL Renderer
    };
  }
}

#endif // BACKGROUND_RENDERER_H