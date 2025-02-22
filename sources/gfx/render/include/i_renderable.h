/**
 * ###############################################################################
 *  File: i_renderable.h
 *  Project: 2D-RPG-Game
 *  Created Date: Tu 18.February 2025, 11:36:33 am
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 22.February 2025, 1:37:07 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef I_RENDERABLE_H
#define I_RENDERABLE_H

namespace gfx
{
  namespace render
  {
    class RendererManager; // forward declaration

    /**
     * @brief Interface class for renderable objects.
     * It provides functions for rendering and updating objects.
     * It also provides a function to set the visibility of the object.
     */
    class IRenderable
    {
      public:
        /**
         * @brief Destroy IRenderable object.
         */
        virtual ~IRenderable() = default;

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
        bool mVisible = true;   // visibility of object
    };
  }
}

#endif // I_RENDERABLE_H