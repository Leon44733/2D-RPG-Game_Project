/**
 * ###############################################################################
 *  File: background_renderer.h
 *  Project: 2D-RPG-Game
 *  Created Date: We 05.March 2025, 2:26:54 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: We 05.March 2025, 2:45:47 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef BACKGROUND_RENDERER_H
#define BACKGROUND_RENDERER_H

#include <SDL.h>
 
namespace gfx
{
  namespace render
  {
    class BackgroundRenderer
    {
      public:
        BackgroundRenderer(SDL_Renderer* aRenderer);
        void render(SDL_Texture* aBgTexture, int aOffsetX, int aOffsetY);

      private:
        SDL_Renderer* mRenderer;
    };
  }
}

#endif // BACKGROUND_RENDERER_H