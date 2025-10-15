/**
 * ###############################################################################
 *  File: background_element.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 08.March 2025, 4:49:37 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: We 15.October 2025, 10:05:57 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include "ui/elements/include/background_element.h"

namespace ui
{
  namespace elem
  {
    BackgroundElement::BackgroundElement(SDL_Texture* aTexture)
    {
      mTexture = aTexture;

      if(mTexture)
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

    BackgroundElement::~BackgroundElement()
    {
      // Note: Do not destroy the texture here, as it is managed by the TextureManager
    }

    void BackgroundElement::render(gfx::render::RendererManager& aRenderer, std::shared_ptr<gfx::render::ICamera> aCamera)
    {
      if(mTexture)
      {
        aRenderer.getBgRenderer().render(*this, aCamera);
      }
    }
  }
}