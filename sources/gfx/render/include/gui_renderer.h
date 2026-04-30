/**
 * ###############################################################################
 *  File: gui_renderer.h
 *  Project: 2D-RPG-Game
 *  Created Date: Tu 18.February 2025, 11:42:25 am
 *  Author: lbarwe
 *  -----
 *  Last Modified: Th 30.April 2026, 10:34:13 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef GUI_RENDERER_H
#define GUI_RENDERER_H

#include <SDL2/SDL.h>
#include <optional>

#include "gfx/render/include/i_renderer.h"

namespace gfx
{
  namespace render
  {
    /**
     * @brief GuiRenderer class for rendering GUI elements.
     */
    class GuiRenderer : public IRenderer
    {
    public:
      /**
       * @brief Construct new GuiRenderer object.
       * @param apRenderer SDL renderer
       */
      GuiRenderer(SDL_Renderer* apRenderer);

      /**
       * @brief Destroy GuiRenderer object.
       */
      ~GuiRenderer();

      /**
       * @brief Render GUI element at position.
       * @param arElem GUI element to render
       * @param arCtx render context (not used)
       */
      void render(const Renderable& arElem, const std::optional<RenderContext>& /*arCtx*/) override;

    private:
      SDL_Renderer* mpRenderer; // SDL renderer
    };
  }
}

#endif // GUI_RENDERER_H