/**
 * ###############################################################################
 *  File: renderable.h
 *  Project: 2D-RPG-Game
 *  Created Date: Tu 18.February 2025, 11:36:33 am
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 08.March 2025, 6:34:41 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <SDL.h>
#include <memory>

#include "gfx/render/include/i_camera.h"

namespace gfx
{
  namespace render
  {
    class RendererManager; // forward declaration

    /**
     * @brief Abstract class for renderable objects.
     * It provides functions for rendering and updating objects.
     * It also provides a function to set the visibility of the object.
     */
    class Renderable
    {
      public:

        /**
         * @brief Render object.
         * @param aRenderer renderer manager
         */
        virtual void render(RendererManager& aRenderer) = 0;
        virtual void render(RendererManager& aRenderer, std::shared_ptr<ICamera> aCamera) = 0;

        SDL_Texture* getTexture() const {return mTexture;}
      
        void setElementSize(int aWidth, int aHeight) {mWidth = aWidth; mHeight = aHeight;}

        int getElementWidth() const {return mWidth;}
        int getElementHeigth() const {return mHeight;}

        void setElementPos(int x, int y) {mPos.x = x; mPos.y = y;}

        SDL_Point getElementPos() const {return mPos;}

        /**
         * @brief Set visibility of object.
         * @param aVisible visibility
         */
        void setVisible(bool aVisible) {mVisible = aVisible;}

        /**
         * @brief Get visibility of object.
         * @return visibility
         */
        bool isVisible() const {return mVisible;}

      protected:
        bool mVisible = true;   // visibility of object
        SDL_Point mPos{0, 0};   // x-pos and y-pos of element
        SDL_Texture* mTexture;  // texture to render
        int mWidth;             // width
        int mHeight;            // height
    };
  }
}

#endif // RENDERABLE_H