/**
 * ###############################################################################
 *  File: renderable.h
 *  Project: 2D-RPG-Game
 *  Created Date: Tu 18.February 2025, 11:36:33 am
 *  Author: lbarwe
 *  -----
 *  Last Modified: Th 06.March 2025, 10:50:38 am
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef RENDERABLE_H
#define RENDERABLE_H

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
         * @brief Construct new Renderable object.
         * Set visibility true by default.
         */
        Renderable() : mVisible(true) {}

        /**
         * @brief Render object.
         * @param aRenderer renderer manager
         */
        virtual void render(RendererManager& aRenderer) = 0;

        /**
         * @brief Update object.
         */
        virtual void update() = 0; // TODO

        /**
         * @brief Set visibility of object.
         * @param aVisible visibility
         */
        void setVisible(bool aVisible) {mVisible = aVisible;};

        /**
         * @brief Get visibility of object.
         * @return visibility
         */
        bool isVisible() const {return mVisible;};

      private:
        bool mVisible;   // visibility of object
    };
  }
}

#endif // RENDERABLE_H