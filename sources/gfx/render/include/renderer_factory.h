/**
 * ###############################################################################
 *  File: renderer_factory.h
 *  Project: 2D-RPG-Game
 *  Created Date: Tu 21.October 2025, 8:29:33 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 14.November 2025, 11:16:59 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef RENDERER_FACTORY_H
#define RENDERER_FACTORY_H

#include <SDL.h>
#include <memory>

#include "gfx/render/include/i_renderer.h"

namespace gfx
{
  namespace render
  {
    enum class RendererType
    {
      BACKGROUND,
      GUI,
      CHARACTER
    };

    class RendererFactory
    {
    public:
      static std::unique_ptr<IRenderer> createRenderer(RendererType aType, SDL_Renderer* aSDLRenderer);
    };
  }
}

#endif // RENDERER_FACTORY_H