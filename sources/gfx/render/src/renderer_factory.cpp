/**
 * ###############################################################################
 *  File: renderer_factory.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Tu 21.October 2025, 8:38:15 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Tu 21.October 2025, 8:42:26 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include "gfx/render/include/renderer_factory.h"
#include "gfx/render/include/background_renderer.h"
#include "gfx/render/include/gui_renderer.h"
#include "gfx/render/include/character_renderer.h"

namespace gfx
{
  namespace render
  {
    std::unique_ptr<IRenderer> RendererFactory::createRenderer(RendererType aType, SDL_Renderer* aSDLRenderer)
    {
      switch (aType)
      {
        case RendererType::BACKGROUND:
          return std::make_unique<BackgroundRenderer>(aSDLRenderer);
        case RendererType::GUI:
          return std::make_unique<GuiRenderer>(aSDLRenderer);
        case RendererType::CHARACTER:
          return std::make_unique<CharacterRenderer>(aSDLRenderer);
        default:
          return nullptr;
      }
    }
  }
}