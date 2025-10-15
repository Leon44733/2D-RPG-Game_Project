/**
 * ###############################################################################
 *  File: renderable.h
 *  Project: 2D-RPG-Game
 *  Created Date: Tu 18.February 2025, 11:36:33 am
 *  Author: lbarwe
 *  -----
 *  Last Modified: We 15.October 2025, 10:20:59 pm
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

      /**
       * @brief Render object using the camera.
       * @param aRender renderer manager
       * @param aCamera camera
       */
      virtual void render(RendererManager& aRenderer, std::shared_ptr<ICamera> aCamera) = 0;

      /**
       * @brief Get element texture.
       * @return texture
       */
      SDL_Texture* getTexture() const { return mTexture; }

      /**
       * @brief Set element size.
       * @param aWidth width
       * @param aHeight hight
       */
      void setElementSize(int aWidth, int aHeight) { mWidth = aWidth; mHeight = aHeight; }

      /**
       * @brief Get element width.
       * @return width
       */
      int getElementWidth() const { return mWidth; }

      /**
       * @brief Get element height.
       * @return height
       */
      int getElementHeight() const { return mHeight; }

      /**
       * @brief Set element position.
       * @param x position
       * @param y position
       */
      void setElementPos(int x, int y) { mPos.x = x; mPos.y = y; }

      /**
       * @brief Get element position.
       * @return position
       */
      SDL_Point getElementPos() const { return mPos; }

      /**
       * @brief Set visibility of object.
       * @param aVisible visibility
       */
      void setVisible(bool aVisible) { mVisible = aVisible; }

      /**
       * @brief Get visibility of object.
       * @return visibility
       */
      bool isVisible() const { return mVisible; }

    protected:
      bool mVisible = true;  // visibility of element
      SDL_Point mPos{0, 0};  // x-pos and y-pos of element
      SDL_Texture* mTexture; // texture to render
      int mWidth;            // element width
      int mHeight;           // element height
    };
  }
}

#endif // RENDERABLE_H