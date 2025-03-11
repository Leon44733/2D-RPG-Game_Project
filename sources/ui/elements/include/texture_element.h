/**
 * ###############################################################################
 *  File: texture_element.h
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 17.January 2025, 12:07:26 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Tu 11.March 2025, 8:50:24 am
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef TEXTURE_ELEMENT_H
#define TEXTURE_ELEMENT_H

#include <SDL.h>

#include "gfx/render/include/renderer_manager.h"
#include "gfx/render/include/renderable.h"
#include "gfx/render/include/i_camera.h"

namespace ui
{
  namespace elem
  {
    /**
     * @brief TextureElement class for rendering textures on the screen.
     * It inherits from Renderable class.
     */
    class TextureElement : public gfx::render::Renderable
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
         * @brief ATTENTION: This function is not needed for TextureElement.
         * @param aRenderer renderer manager
         * @param aCamera camera
         */
        [[maybe_unused]] void render([[maybe_unused]] gfx::render::RendererManager& aRenderer, [[maybe_unused]] std::shared_ptr<gfx::render::ICamera> aCamera) override {};
    };
  }
}

#endif // TEXTURE_ELEMENT_H