/**
 * ###############################################################################
 *  File: i_renderer.h
 *  Project: 2D-RPG-Game
 *  Created Date: Tu 21.October 2025, 8:32:28 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 14.November 2025, 11:52:41 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef I_RENDERER_H
#define I_RENDERER_H

#include "gfx/render/include/renderable.h"
#include "gfx/render/include/render_context.h"

namespace gfx
{
  namespace render
  {
    /**
     * @brief Interface for renderer classes.
     * It provides a virtual render function to be implemented by derived classes.
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
       * @param aElem renderable element to render
       * @param aCtx render context. Is not always needed.
       */
      virtual void render(const Renderable& aElem, const std::optional<RenderContext>& aCtx) = 0;
    };
  }
}

#endif // I_RENDERER_H