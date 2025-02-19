/**
 * ###############################################################################
 *  File: gui_renderer.h
 *  Project: 2D-RPG-Game
 *  Created Date: Tu 18.February 2025, 11:42:25 am
 *  Author: lbarwe
 *  -----
 *  Last Modified: We 19.February 2025, 9:58:53 am
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef GUI_RENDERER_H
#define GUI_RENDERER_H

#include <SDL.h>

namespace GFX
{
  namespace Render
  {
    class GuiRenderer
    {
      public:
        explicit GuiRenderer(SDL_Renderer*);
        ~GuiRenderer();

        void render(SDL_Texture*, int, int, int, int);

      private:
        SDL_Renderer* mRenderer;
    };
  }
}

#endif // GUI_RENDERER_H