/**
 * ###############################################################################
 *  File: background_renderer.h
 *  Project: 2D-RPG-Game
 *  Created Date: We 05.March 2025, 2:26:54 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Mo 10.March 2025, 2:05:10 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef BACKGROUND_RENDERER_H
#define BACKGROUND_RENDERER_H

#include <SDL.h>
#include <memory>

#include "gfx/render/include/i_camera.h"
#include "gfx/render/include/renderable.h"
 
namespace gfx
{
  namespace render
  {
    /**
     * @brief BackgroundRenderer class for rendering background textures.
     */
    class BackgroundRenderer
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
         * @brief Render background texture at position.
         * @param aElem background element to render
         * @param aCamera camera
         */
        void render(const Renderable& aElem, std::shared_ptr<ICamera> aCamera);

      private:
        SDL_Renderer* mRenderer;  // SDL Renderer
    };
  }
}

#endif // BACKGROUND_RENDERER_H