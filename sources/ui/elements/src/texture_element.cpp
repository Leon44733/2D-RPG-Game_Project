/**
 * ###############################################################################
 *  File: texture_element.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 17.January 2025, 12:07:16 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 06.February 2026, 9:38:45 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include "ui/elements/include/texture_element.h"

#include "gfx/render/include/renderer_manager.h"
#include "gfx/render/include/i_renderer.h"

namespace ui
{
  namespace elem
  {
    TextureElement::TextureElement(SDL_Texture* apTexture)
    {
      mpTexture = apTexture;

      if(mpTexture)
      {
        // Query texture for its width and height
        SDL_QueryTexture(mpTexture, nullptr, nullptr, &mWidth, &mHeight);
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

    TextureElement::~TextureElement()
    {
      // Note: Do not destroy the texture here, as it is managed by the TextureManager
    }

    void TextureElement::render(gfx::render::RendererManager& arRenderer)
    {
      if(mpTexture)
      {
        arRenderer.getGuiRenderer().render(*this, std::nullopt);
      }
    }
  }
}