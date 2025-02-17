/**
 * ###############################################################################
 *  File: gui_element_base.h
 *  Project: 2D-RPG-Game
 *  Created Date: Su 09.February 2025, 11:57:00 am
 *  Author: lbarwe
 *  -----
 *  Last Modified: Tu 18.February 2025, 11:20:10 am
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef GUI_ELEMENT_BASE_H
#define GUI_ELEMENT_BASE_H

#include <SDL2/SDL.h>

namespace UI
{
  namespace ELEM
  {
    struct GuiElementBase
    {
      virtual ~GuiElementBase() = default;

      virtual void render(SDL_Renderer*) = 0;
      virtual void update() = 0;
      
      virtual void setElementSize(int, int) = 0;
      virtual void setElementPos(int, int) = 0;
      virtual void handleEvent(SDL_Event&) = 0;
      
      void setVisible(bool);
      bool isVisible() const;

      protected:
      bool mVisible = true;       // element visibilty
      SDL_Point mPos{0, 0};       // x-pos and y-pos
    };
  }
}

#endif // GUI_ELEMENT_BASE_H