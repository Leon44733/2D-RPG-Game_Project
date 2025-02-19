/**
 * ###############################################################################
 *  File: i_gui_element.h
 *  Project: 2D-RPG-Game
 *  Created Date: Su 09.February 2025, 11:57:00 am
 *  Author: lbarwe
 *  -----
 *  Last Modified: We 19.February 2025, 10:37:57 am
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef I_GUI_ELEMENT_H
#define I_GUI_ELEMENT_H

#include <SDL.h>

#include "gfx/render/include/i_renderable.h"

namespace GFX
{
  namespace Render
  {
     class RendererManager; // forward declaration
  }
}

namespace UI
{
  namespace ELEM
  {
    class IGuiElement : public GFX::Render::IRenderable
    {
      public:
        virtual ~IGuiElement() = default;
      
        virtual void setElementSize(int, int) = 0;
        virtual void setElementPos(int, int) = 0;
        virtual void handleEvent(SDL_Event&) = 0;
        
      protected:
        SDL_Point mPos{0, 0};       // x-pos and y-pos
    };
  }
}

#endif // I_GUI_ELEMENT_H