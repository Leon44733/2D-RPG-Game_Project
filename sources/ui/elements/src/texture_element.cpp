/**
 * ###############################################################################
 *  File: texture_element.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 17.January 2025, 12:07:16 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 07.March 2025, 1:56:42 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include "ui/elements/include/texture_element.h"

namespace ui
{
  namespace elem
  {
    TextureElement::TextureElement(SDL_Texture* aTexture)
    {
      mTexture = aTexture;

      if (mTexture)
      {
        // Query texture for its width and height
        SDL_QueryTexture(mTexture, nullptr, nullptr, &mWidth, &mHeight);
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

    void TextureElement::render(gfx::render::RendererManager& aRenderer)
    {
      if(mTexture)
      {
        aRenderer.getGuiRenderer().render(*this);
      }
    }
  }
}

