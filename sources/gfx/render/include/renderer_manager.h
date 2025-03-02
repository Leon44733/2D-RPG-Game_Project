/**
 * ###############################################################################
 *  File: renderer_manager.h
 *  Project: 2D-RPG-Game
 *  Created Date: Su 09.February 2025, 12:47:07 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 01.March 2025, 3:32:53 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef RENDERER_MANAGER_H
#define RENDERER_MANAGER_H

#include <SDL.h>
#include <vector>
#include <memory>

#include "gfx/render/include/i_renderable.h"
#include "gfx/render/include/gui_renderer.h"
#include "gfx/render/include/character_renderer.h"

namespace gfx
{
    namespace render
    {
        /**
         * @brief RendererManager class for managing the renderers.
         */
        class RendererManager
        {
            public:
                /**
                 * @brief Construct new RendererManager object.
                 * @param aWindow* window
                 */
                RendererManager(SDL_Window* aWindow);

                /**
                 * @brief Destroy RendererManager object.
                 * This function also destroys the renderer.
                 */
                ~RendererManager();
                
                /**
                 * @brief Add renderable element to the renderer.
                 * @param aElement shared pointer to renderable element
                 */
                void addRenderable(std::shared_ptr<IRenderable> aElement);

                /**
                 * @brief Render all renderable elements in the renderables vector.
                 * It also clears the renderer before rendering.
                 */
                void renderAll();

                /**
                 * @brief Update all renderable elements in the renderables vector.
                 * This function calls the update function of each renderable element.
                 */
                void updateAll();
                
                /**
                 * @brief Get SDL renderer.
                 * @return SDL_Renderer* sdl renderer
                 */
                SDL_Renderer* getRenderer() const;

                /**
                 * @brief Get GuiRenderer object.
                 * @return GuiRenderer& gui renderer
                 */
                GuiRenderer& getGuiRenderer();

                /**
                 * @brief Get CharacterRenderer object.
                 * @return CharacterRenderer& character renderer
                 */
                CharacterRenderer& getCharacterRenderer();

            private:
                SDL_Renderer* mRenderer;                                    // sdl renderer
                std::vector<std::shared_ptr<IRenderable>> mRenderables;     // vector of renderable elements
                GuiRenderer mGuiRenderer;                                   // gui renderer
                CharacterRenderer mCharacterRenderer;                       // character renderer
        };
    }
}

#endif // RENDERER_MANAGER_H