/**
 * ###############################################################################
 *  File: i_renderable.h
 *  Project: 2D-RPG-Game
 *  Created Date: Tu 18.February 2025, 11:36:33 am
 *  Author: lbarwe
 *  -----
 *  Last Modified: Tu 18.February 2025, 2:34:36 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef I_RENDERABLE_H
#define I_RENDERABLE_H

namespace GFX
{
  namespace Render
  {
    class RendererManager; // forward declaration

    class IRenderable
    {
      public:
        virtual ~IRenderable() = default;
        virtual void render(RendererManager&) = 0;
        virtual void update() = 0;

        void setVisible(bool aVisible) {mVisible = aVisible;};
        bool isVisible() const {return mVisible;};

      private:
        bool mVisible = true;
    };
  }
}

#endif // I_RENDERABLE_H