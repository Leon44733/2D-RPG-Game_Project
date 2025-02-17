/**
 * ###############################################################################
 *  File: i_gui_element.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Su 09.February 2025, 2:09:32 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Tu 18.February 2025, 11:12:30 am
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include "sources/ui/elements/include/gui_element_base.h"

namespace UI
{
  namespace ELEM
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