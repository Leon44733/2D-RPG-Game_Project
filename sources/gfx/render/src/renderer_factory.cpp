/**
 * ###############################################################################
 *  File: renderer_factory.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Tu 21.October 2025, 8:38:15 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 15.November 2025, 4:35:53 pm
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
    std::unique_ptr<IRenderer> RendererFactory::createRenderer(RendererType aType, SDL_Renderer* apRenderer)
    {
      // create renderer based on type
      switch (aType)
      {
        case RendererType::BACKGROUND:
          return std::make_unique<BackgroundRenderer>(apRenderer);

        case RendererType::GUI:
          return std::make_unique<GuiRenderer>(apRenderer);

        case RendererType::CHARACTER:
          return std::make_unique<CharacterRenderer>(apRenderer);
          
        default:
          return nullptr;
      }
    }
  }
}