/**
 * ###############################################################################
 *  File: gui_renderer.h
 *  Project: 2D-RPG-Game
 *  Created Date: Tu 18.February 2025, 11:42:25 am
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 22.February 2025, 1:34:31 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef GUI_RENDERER_H
#define GUI_RENDERER_H

#include <SDL.h>

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
        explicit GuiRenderer(SDL_Renderer* aRenderer);
        
        /**
         * @brief Destroy GuiRenderer object.
         */
        ~GuiRenderer();

        /**
         * @brief Render texture at position.
         * @param aTexture texture to render
         * @param x x-position
         * @param y y-position
         * @param aWidth texture width
         * @param aHeight texture height
         */
        void render(SDL_Texture*, int, int, int, int);

      private:
        SDL_Renderer* mRenderer;    // SDL renderer
    };
  }
}

#endif // GUI_RENDERER_H