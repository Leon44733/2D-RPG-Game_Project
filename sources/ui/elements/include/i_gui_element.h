/**
 * ###############################################################################
 *  File: i_gui_element.h
 *  Project: 2D-RPG-Game
 *  Created Date: Su 09.February 2025, 11:57:00 am
 *  Author: lbarwe
 *  -----
 *  Last Modified: Th 06.March 2025, 10:47:27 am
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef I_GUI_ELEMENT_H
#define I_GUI_ELEMENT_H

#include <SDL.h>

#include "gfx/render/include/i_renderable.h"

namespace gfx
{
  namespace render
  {
     class RendererManager; // forward declaration
  }
}

namespace ui
{
  namespace elem
  {
    /**
     * @brief Interface class for GUI elements.
     * It also inherits from Renderable class.
     */
    class IGuiElement : public gfx::render::Renderable
    {
      public:
        /**
         * @brief Destroy IGuiElement object.
         */
        virtual ~IGuiElement() = default;
      
        /**
         * @brief Set size of element.
         * @param aWidth element width
         * @param aHeight element height
         */
        virtual void setElementSize(int aWidth, int aHeight) = 0;

        /**
         * @brief Set position of element.
         * @param x x-position
         * @param y y-position
         */
        virtual void setElementPos(int x, int y) = 0;
        
        /**
         * @brief Handle events for element.
         * @param aEvent SDL event
         */
        virtual void handleEvent(SDL_Event& aEvent) = 0;
        
      protected:
        SDL_Point mPos{0, 0};   // x-pos and y-pos of element
    };
  }
}

#endif // I_GUI_ELEMENT_H