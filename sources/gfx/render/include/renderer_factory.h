/**
 * ###############################################################################
 *  File: renderer_factory.h
 *  Project: 2D-RPG-Game
 *  Created Date: Tu 21.October 2025, 8:29:33 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 01.May 2026, 6:55:26 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef RENDERER_FACTORY_H
#define RENDERER_FACTORY_H

#include <SDL3/SDL.h>
#include <memory>

namespace gfx
{
  namespace render
  {
    // forward declaration
    class IRenderer;

    /**
     * @brief Enum class for different renderer types.
     */
    enum class RendererType
    {
      BACKGROUND, // Background renderer
      GUI,        // GUI renderer
      CHARACTER   // Character renderer
    };

    class RendererFactory
    {
    public:
      /**
       * @brief Create a renderer of the specified type.
       * @param aType type of renderer to create
       * @param apRenderer SDL renderer
       * @return unique pointer to the created renderer
       */
      static std::unique_ptr<IRenderer> createRenderer(RendererType aType, SDL_Renderer* apRenderer);
    };
  }
}

#endif // RENDERER_FACTORY_H