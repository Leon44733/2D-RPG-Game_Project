/**
 * ###############################################################################
 *  File: renderer_manager.h
 *  Project: 2D-RPG-Game
 *  Created Date: Su 09.February 2025, 12:47:07 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 08.March 2025, 7:06:56 pm
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
#include <unordered_map>

#include "gfx/render/include/renderable.h"
#include "gfx/render/include/background_renderer.h"
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
                void addGuiRenderable(std::shared_ptr<Renderable> aElem);

                /**
                 * @brief Render all renderable elements in the renderables vector.
                 * It also clears the renderer before rendering.
                 */
                void renderAllGuiElem();
                
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
                CharacterRenderer& getCharRenderer();
                void addCharRenderable(std::shared_ptr<Renderable> aElem, std::string aName);
                Renderable& getCharElement(std::string aName);
                void renderCharElement(std::string aName, std::shared_ptr<ICamera> aCamera);


                BackgroundRenderer& getBgRenderer();
                void addBgRenderable(std::shared_ptr<Renderable> aElem, std::string aName);
                Renderable& getBgElement(std::string aName);
                void renderBgElement(std::string aName,  std::shared_ptr<ICamera> aCamera);

            private:
                SDL_Renderer* mRenderer;                                    // sdl renderer
                BackgroundRenderer mBgRenderer;                             // background renderer
                GuiRenderer mGuiRenderer;                                   // gui renderer
                CharacterRenderer mCharRenderer;                            // character renderer
                std::vector<std::shared_ptr<Renderable>> mGuiElements;      // vector of gui elements
                std::unordered_map<std::string, std::shared_ptr<Renderable>> mBgElements;    // map of background elements
                std::unordered_map<std::string, std::shared_ptr<Renderable>> mCharElements;    // map of character elements
        };
    }
}

#endif // RENDERER_MANAGER_H