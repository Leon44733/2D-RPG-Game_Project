/**
 * ###############################################################################
 *  File: render_context.h
 *  Project: 2D-RPG-Game
 *  Created Date: Tu 21.October 2025, 8:58:29 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 06.February 2026, 8:54:26 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef RENDER_CONTEXT_H
#define RENDER_CONTEXT_H

#include <memory>

namespace gfx
{
  namespace render
  {
    //forward declaration
    class ICamera;

    /**
     * @brief RenderContext struct for holding rendering context information.
     */
    struct RenderContext
    {
      std::shared_ptr<ICamera> mpCamera = nullptr; // camera used for rendering
    };
  }
}

#endif // RENDER_CONTEXT_H