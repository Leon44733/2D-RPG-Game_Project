/**
 * ###############################################################################
 *  File: renderer_manager.h
 *  Project: 2D-RPG-Game
 *  Created Date: Su 09.February 2025, 12:47:07 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 15.February 2025, 12:40:41 pm
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

#include "src/ui/include/i_gui_element.h"

namespace UI
{
    namespace GUI
    {
        class RendererManager
        {
            public:
                RendererManager(SDL_Window*);
                ~RendererManager();

                SDL_Renderer* getRenderer() const;

                void addGuiElement(std::shared_ptr<GUI::IGuiElement>);
                void renderAllElements();
                void updateAllElements();

            private:
                SDL_Renderer* mRenderer;
                std::vector<std::shared_ptr<GUI::IGuiElement>> mGuiElements;
        };
    }
}

#endif // RENDERER_MANAGER_H