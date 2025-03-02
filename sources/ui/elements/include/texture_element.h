/**
 * ###############################################################################
 *  File: texture_element.h
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 17.January 2025, 12:07:26 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 01.March 2025, 6:55:05 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef TEXTURE_ELEMENT_H
#define TEXTURE_ELEMENT_H

#include "ui/elements/include/i_gui_element.h"

namespace ui
{
  namespace elem
  {
    /**
     * @brief TextureElement class for rendering textures on the screen.
     * It inherits from IGuiElement class.
     */
    class TextureElement : public IGuiElement
    {
      public:
        /**
         * @brief Construct new TextureElement object.
         * @param aTexture texture to render
         */
        TextureElement(SDL_Texture* aTexture);
        
        /**
         * @brief Destroy TextureElement object.
         */
        ~TextureElement();

        /**
         * @brief Render texture element by passing the renderer manager.
         * @param aRenderer renderer manager
         */
        void render(gfx::render::RendererManager& aRenderer) override;

        /**
         * @brief Update texture element.
         * TODO: This function is not implemented yet.
         */
        void update() override;
        
        /**
         * @brief Set size of element.
         * @param aWidth element width
         * @param aHeight element height
         */
        void setElementSize(int aWidth, int aHeight) override;
        
        /**
         * @brief Set position of element.
         * @param x x-position
         * @param y y-position
         */
        void setElementPos(int x, int y) override;

        /**
         * @brief Handle events for the element.
         * @param aEvent event to handle
         */
        void handleEvent(SDL_Event& aEvent) override; //TODO

      private:
        SDL_Texture* mTexture;    // texture to render
        int mWidth;               // element width
        int mHeight;              // element height
    };
  }
}

#endif // TEXTURE_ELEMENT_H