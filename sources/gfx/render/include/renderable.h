/**
 * ###############################################################################
 *  File: renderable.h
 *  Project: 2D-RPG-Game
 *  Created Date: Tu 18.February 2025, 11:36:33 am
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 01.May 2026, 7:59:54 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <SDL3/SDL.h>
#include <memory>

namespace gfx
{
  namespace render
  {
    // forward declarations
    class RendererManager;
    class ICamera;

    /**
     * @brief Abstract class for renderable objects.
     *        It provides functions for rendering and updating objects.
     *        It also provides a function to set the visibility of the object.
     */
    class Renderable
    {
    public:
      /**
       * @brief Render object.
       * @param arRenderer renderer manager
       */
      virtual void render(RendererManager& arRenderer) = 0;

      /**
       * @brief Render object using the camera.
       * @param arRenderer renderer manager
       * @param apCamera camera
       */
      virtual void render(RendererManager& arRenderer, std::shared_ptr<ICamera> apCamera) = 0;

      /**
       * @brief Get element texture.
       * @return texture
       */
      SDL_Texture* getTexture() const { return mpTexture; }

      /**
       * @brief Set element size.
       * @param aWidth element width
       * @param aHeight element hight
       */
      void setElementSize(float aWidth, float aHeight) { mWidth = aWidth; mHeight = aHeight; }

      /**
       * @brief Get element width.
       * @return element width
       */
      float getElementWidth() const { return mWidth; }

      /**
       * @brief Get element height.
       * @return element height
       */
      float getElementHeight() const { return mHeight; }

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
      SDL_FPoint getElementPos() const { return mPos; }

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
      SDL_Texture* mpTexture;      // texture to render
      SDL_FPoint   mPos{0, 0};     // x-pos and y-pos of element
      bool         mVisible{true}; // visibility of element
      float        mWidth;         // element width
      float        mHeight;        // element height
    };
  }
}

#endif // RENDERABLE_H