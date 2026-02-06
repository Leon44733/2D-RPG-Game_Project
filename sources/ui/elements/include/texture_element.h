/**
 * ###############################################################################
 *  File: texture_element.h
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 17.January 2025, 12:07:26 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 06.February 2026, 9:36:08 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef TEXTURE_ELEMENT_H
#define TEXTURE_ELEMENT_H

#include <SDL.h>

#include "gfx/render/include/renderable.h"

namespace gfx::render
{
  // forward declarations
  class RendererManager;
  class ICamera;
}

namespace ui
{
  namespace elem
  {
    /**
     * @brief TextureElement class for rendering textures on the screen.
     *        It inherits from Renderable class.
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
       * @param arRenderer renderer manager
       */
      void render(gfx::render::RendererManager& arRenderer) override;

      /**
       * @brief ATTENTION: This function is not needed for TextureElement.
       * @param arRenderer renderer manager
       * @param arCamera camera
       */
      [[maybe_unused]] void render([[maybe_unused]] gfx::render::RendererManager& arRenderer, [[maybe_unused]] std::shared_ptr<gfx::render::ICamera> arCamera) override {};
    };
  }
}

#endif // TEXTURE_ELEMENT_H