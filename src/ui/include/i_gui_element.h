/**
 * ###############################################################################
 *  File: i_gui_element.h
 *  Project: 2D-RPG-Game
 *  Created Date: Su 09.February 2025, 11:57:00 am
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 15.February 2025, 1:17:33 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef I_GUI_ELEMENT_H
#define I_GUI_ELEMENT_H

#include <SDL2/SDL.h>

namespace UI
{
  namespace GUI
  {
    struct IGuiElement
    {
      virtual ~IGuiElement() = default;

      virtual void render(SDL_Renderer*) = 0;
      virtual void update() = 0;
      
      virtual void setElementSize(int, int) = 0;
      virtual void setElementPos(int, int) = 0;
      virtual void handleEvent(SDL_Event&) = 0;
      
      void setVisible(bool);
      bool isVisible() const;

      protected:
      bool mVisible = true;       // element visibilty
      int mXPos = 0;              // x-position
      int mYPos = 0;              // y-position
      int mWidth;                 // element width
      int mHeight;                // element height
    };
  }
}

#endif // I_GUI_ELEMENT_H