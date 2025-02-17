/**
 * ###############################################################################
 *  File: texture_element.h
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 17.January 2025, 12:07:26 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Tu 18.February 2025, 11:12:52 am
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef TEXTURE_ELEMENT_H
#define TEXTURE_ELEMENT_H

#include <string>
#include <SDL2/SDL.h>

#include "sources/ui/elements/include/gui_element_base.h"

namespace UI
{
  namespace ELEM
  {
    class TextureElement : public GuiElementBase
    {
      public:
        TextureElement(SDL_Texture*);
        ~TextureElement();

        void render(SDL_Renderer*) override;
        void update() override;
        
        void setElementSize(int, int) override;
        void setElementPos(int, int) override;
        void handleEvent(SDL_Event&) override;

      private:
        SDL_Texture* mTexture;    // element texture
        int mWidth;               // element width
        int mHeight;              // element height
    };
  }
}

#endif // TEXTURE_ELEMENT_H