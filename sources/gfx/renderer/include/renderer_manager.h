/**
 * ###############################################################################
 *  File: renderer_manager.h
 *  Project: 2D-RPG-Game
 *  Created Date: Su 09.February 2025, 12:47:07 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Tu 18.February 2025, 11:10:48 am
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef RENDERER_MANAGER_H
#define RENDERER_MANAGER_H

#include <SDL2/SDL.h>
#include <vector>
#include <memory>

#include "sources/ui/elements/include/gui_element_base.h"

namespace GFX
{
    namespace Render
    {
        class RendererManager
        {
            public:
                RendererManager(SDL_Window*);
                ~RendererManager();

                SDL_Renderer* getRenderer() const;

                void addGuiElement(std::shared_ptr<UI::ELEM::GuiElementBase>);
                void renderAllElements();
                void updateAllElements();

            private:
                SDL_Renderer* mRenderer;
                std::vector<std::shared_ptr<UI::ELEM::GuiElementBase>> mGuiElements;
        };
    }
}

#endif // RENDERER_MANAGER_H