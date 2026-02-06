/**
 * ###############################################################################
 *  File: i_renderer.h
 *  Project: 2D-RPG-Game
 *  Created Date: Tu 21.October 2025, 8:32:28 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 06.February 2026, 8:50:58 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef I_RENDERER_H
#define I_RENDERER_H

#include <optional>
#include "gfx/render/include/render_context.h"

namespace gfx
{
  namespace render
  {
    //forward declarations
    class Renderable;

    /**
     * @brief Interface for renderer classes.
     *        It provides a virtual render function to be implemented by derived classes.
     */
    class IRenderer
    {
    public:
      /**
       * @brief Virtual destructor for IRenderer.
       */
      virtual ~IRenderer() = default;

      /**
       * @brief Virtual render function to be implemented by derived classes.
       * @param arElem renderable element to render
       * @param arCtx render context. Is not always needed.
       */
      virtual void render(const Renderable& arElem, const std::optional<RenderContext>& arCtx) = 0;
    };
  }
}

#endif // I_RENDERER_H