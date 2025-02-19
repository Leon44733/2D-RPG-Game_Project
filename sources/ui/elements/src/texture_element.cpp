/**
 * ###############################################################################
 *  File: texture_element.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 17.January 2025, 12:07:16 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Tu 18.February 2025, 3:22:56 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include <iostream>

#include "ui/elements/include/texture_element.h"
#include "gfx/render/include/renderer_manager.h"

namespace UI
{
  namespace ELEM
  {
    TextureElement::TextureElement(SDL_Texture* aTexture) :
      mTexture(aTexture)
    {
      if (mTexture)
      {
        // Query the texture to get its actual width and height
        SDL_QueryTexture(mTexture, nullptr, nullptr, &mWidth, &mHeight);
      }
      else
      {
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

    void TextureElement::render(GFX::Render::RendererManager& aRenderer)
    {
      if(mTexture)
      {
        aRenderer.getGuiRenderer().render(mTexture, mPos.x, mPos.y, mWidth, mHeight);
      }
    }

    void TextureElement::update()
    {
      // TODO: Update logic for the texture element
    }

    void TextureElement::setElementSize(int aWidth, int aHeight)
    {
      mWidth = aWidth;
      mHeight = aHeight;
    }

    void TextureElement::setElementPos(int x, int y)
    {
      mPos.x = x;
      mPos.y = y;
    }

    void TextureElement::handleEvent(SDL_Event& aEvent)
    {
      // TODO: Handle events for the texture element
    }
  }
}

