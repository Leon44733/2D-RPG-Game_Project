/**
 * ###############################################################################
 *  File: background_element.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 08.March 2025, 4:49:37 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 01.May 2026, 8:05:39 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include "ui/elements/include/background_element.h"

#include "gfx/render/include/renderer_manager.h"
#include "gfx/render/include/i_renderer.h"

namespace ui
{
  namespace elem
  {
    BackgroundElement::BackgroundElement(SDL_Texture* apTexture)
    {
      mpTexture = apTexture;

      if(mpTexture)
      {
        // Query texture for its width and height
        float w, h = 0.f;
        SDL_GetTextureSize(mpTexture, &w, &h);
        mWidth = w;
        mHeight = h;
      }
      else
      {
        // Set default values if texture is not valid
        mPos.x = 0;
        mPos.y = 0;
        mWidth = 100;
        mHeight = 100;
      }
    }

    BackgroundElement::~BackgroundElement()
    {
      // Note: Do not destroy the texture here, as it is managed by the TextureManager
    }

    void BackgroundElement::render(gfx::render::RendererManager& arRenderer, std::shared_ptr<gfx::render::ICamera> arCamera)
    {
      if(mpTexture)
      {
        gfx::render::RenderContext ctx{arCamera};
        arRenderer.getBgRenderer().render(*this, ctx);
      }
    }
  }
}