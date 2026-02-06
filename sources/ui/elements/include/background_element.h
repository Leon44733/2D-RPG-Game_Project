/**
 * ###############################################################################
 *  File: background_element.h
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 08.March 2025, 4:49:27 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 06.February 2026, 9:34:01 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef BACKGROUND_ELEMENT_H
#define BACKGROUND_ELEMENT_H

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
     * @brief BackgroundElement class for rendering the background.
     *        It inherits from Renderable class.
     */
    class BackgroundElement : public gfx::render::Renderable
    {
    public:
      /**
       * @brief Construct new BackgroundElement object.
       * @param aTexture background to render
       */
      BackgroundElement(SDL_Texture* aTexture);

      /**
       * @brief Destroy BackgroundElement object.
       */
      ~BackgroundElement();

      /**
       * @brief ATTENTION: This function is not needed for BackgroundElement.
       * @param arRenderer renderer manager
       */
      [[maybe_unused]] void render([[maybe_unused]] gfx::render::RendererManager& arRenderer) override {};

      /**
       * @brief Render background element by passing the renderer manager and the camera.
       * @param arRenderer renderer manager
       * @param apCamera camera
       */
      void render(gfx::render::RendererManager& arRenderer, std::shared_ptr<gfx::render::ICamera> apCamera) override;
    };
  }
}

#endif // BACKGROUND_ELEMENT_H