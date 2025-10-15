/**
 * ###############################################################################
 *  File: gui_renderer.h
 *  Project: 2D-RPG-Game
 *  Created Date: Tu 18.February 2025, 11:42:25 am
 *  Author: lbarwe
 *  -----
 *  Last Modified: We 15.October 2025, 10:21:21 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef GUI_RENDERER_H
#define GUI_RENDERER_H

#include <SDL.h>

#include "gfx/render/include/renderable.h"

namespace gfx
{
  namespace render
  {
    /**
     * @brief GuiRenderer class for rendering GUI elements.
     */
    class GuiRenderer
    {
    public:
      /**
       * @brief Construct new GuiRenderer object.
       * @param aRenderer SDL renderer
       */
      GuiRenderer(SDL_Renderer* aRenderer);

      /**
       * @brief Destroy GuiRenderer object.
       */
      ~GuiRenderer();

      /**
       * @brief Render gui element.
       * @param aElement gui element to render
       */
      void render(const Renderable& aElem);

    private:
      SDL_Renderer* mRenderer; // SDL renderer
    };
  }
}

#endif // GUI_RENDERER_H