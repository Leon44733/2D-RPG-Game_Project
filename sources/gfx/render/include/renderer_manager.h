/**
 * ###############################################################################
 *  File: renderer_manager.h
 *  Project: 2D-RPG-Game
 *  Created Date: Su 09.February 2025, 12:47:07 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Mo 10.March 2025, 2:22:06 pm
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
                 * @brief Add renderable element to vector.
                 * @param aElem shared pointer to renderable element
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

                /**
                 * @brief Add renderable character element to unordered map.
                 * @param aElem shared pointer to renderable element
                 * @param aName identifier name of renderable character
                 */
                void addCharRenderable(std::shared_ptr<Renderable> aElem, std::string aName);

                /**
                 * @brief Get character element from unordered map.
                 * @return renderable character
                 */
                Renderable& getCharElement(std::string aName);

                /**
                 * @brief Render character element.
                 * @param aName identifier name of renderable character
                 */
                void renderCharElement(std::string aName);

                /**
                 * @brief Get BackgroundRenderer object.
                 * @return BackgroundRenderer& background renderer
                 */
                BackgroundRenderer& getBgRenderer();

                /**
                 * @brief Add renderable background object to unordered map.
                 * @param aElem shared pointer to renderable element
                 * @param aName identifier name of renderable background
                 */
                void addBgRenderable(std::shared_ptr<Renderable> aElem, std::string aName);

                /**
                 * @brief Get background element from unordered map.
                 * @return renderable background
                 */
                Renderable& getBgElement(std::string aName);
                
                /**
                 * @brief Render background element.
                 * @param aName identifier name of renderable background
                 * @param aCamera camera
                 */
                void renderBgElement(std::string aName,  std::shared_ptr<ICamera> aCamera);

            private:
                SDL_Renderer* mRenderer;                                                        // sdl renderer
                BackgroundRenderer mBgRenderer;                                                 // background renderer
                GuiRenderer mGuiRenderer;                                                       // gui renderer
                CharacterRenderer mCharRenderer;                                                // character renderer
                std::vector<std::shared_ptr<Renderable>> mGuiElements;                          // vector of gui elements
                std::unordered_map<std::string, std::shared_ptr<Renderable>> mBgElements;       // map of background elements
                std::unordered_map<std::string, std::shared_ptr<Renderable>> mCharElements;     // map of character elements
        };
    }
}

#endif // RENDERER_MANAGER_H