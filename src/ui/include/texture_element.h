/**
 * ###############################################################################
 *  File: texture_element.h
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 17.January 2025, 12:07:26 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Su 09.February 2025, 1:51:01 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef TEXTURE_ELEMENT_H
#define TEXTURE_ELEMENT_H

#include <string>
#include <SDL2/SDL.h>

#include "src/ui/include/i_gui_element.h"

namespace UI
{
  namespace GUI
  {
    class TextureElement : public IGuiElement
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
        SDL_Texture* mTexture;    // element-texture
    };
  }
}

#endif // TEXTURE_ELEMENT_H