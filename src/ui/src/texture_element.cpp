/**
 * ###############################################################################
 *  File: texture_element.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 17.January 2025, 12:07:16 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Su 09.February 2025, 1:56:47 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include <iostream>

#include "src/ui/include/texture_element.h"
#include "src/ui/include/texture_manager.h"

namespace UI
{
  namespace GUI
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
        mXPos = 0;
        mYPos = 0;
        mWidth = 100;
        mHeight = 100;
      }
    }

    TextureElement::~TextureElement()
    {
      // Note: Do not destroy the texture here, as it is managed by the TextureManager
    }

    void TextureElement::render(SDL_Renderer* renderer)
    {
        if(mTexture)
        {
            SDL_Rect dstRect = { mXPos, mYPos, mWidth, mHeight };
            SDL_RenderCopy(renderer, mTexture, nullptr, &dstRect);
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

    void TextureElement::setElementPos(int aXPos, int aYPos)
    {
      mXPos = aXPos;
      mYPos = aYPos;
    }

    void TextureElement::handleEvent(SDL_Event& event)
    {
      // TODO: Handle events for the texture element
    }
  }
}

