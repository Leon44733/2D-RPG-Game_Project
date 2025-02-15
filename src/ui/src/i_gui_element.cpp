/**
 * ###############################################################################
 *  File: i_gui_element.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Su 09.February 2025, 2:09:32 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Su 09.February 2025, 2:09:37 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include "src/ui/include/i_gui_element.h"

namespace UI
{
  namespace GUI
  {
    void IGuiElement::setVisible(bool visible)
    {
      mVisible = visible;
    }

    bool IGuiElement::isVisible() const
    {
      return mVisible;
    }
  }
}