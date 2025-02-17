/**
 * ###############################################################################
 *  File: i_gui_element.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Su 09.February 2025, 2:09:32 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Mo 17.February 2025, 1:31:26 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include "src/ui/include/gui_element_base.h"

namespace UI
{
  namespace GUI
  {
    void GuiElementBase::setVisible(bool visible)
    {
      mVisible = visible;
    }

    bool GuiElementBase::isVisible() const
    {
      return mVisible;
    }
  }
}