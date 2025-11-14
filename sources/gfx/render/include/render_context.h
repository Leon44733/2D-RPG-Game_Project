/**
 * ###############################################################################
 *  File: render_context.h
 *  Project: 2D-RPG-Game
 *  Created Date: Tu 21.October 2025, 8:58:29 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 14.November 2025, 11:59:13 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef RENDER_CONTEXT_H
#define RENDER_CONTEXT_H

#include <memory>

#include "gfx/render/include/i_camera.h"

namespace gfx
{
  namespace render
  {
    /**
     * @brief RenderContext struct for holding rendering context information.
     */
    struct RenderContext
    {
      std::shared_ptr<ICamera> camera = nullptr; // Camera used for rendering
    };
  }
}

#endif // RENDER_CONTEXT_H