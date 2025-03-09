/**
 * ###############################################################################
 *  File: background_renderer.h
 *  Project: 2D-RPG-Game
 *  Created Date: We 05.March 2025, 2:26:54 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 08.March 2025, 4:48:01 pm
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
    class BackgroundRenderer
    {
      public:
        BackgroundRenderer(SDL_Renderer* aRenderer);
        ~BackgroundRenderer();
        
        void render(const Renderable& aElem, std::shared_ptr<ICamera> aCamera);

      private:
        SDL_Renderer* mRenderer;
    };
  }
}

#endif // BACKGROUND_RENDERER_H