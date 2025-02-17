/**
 * ###############################################################################
 *  File: renderer_manager.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Su 09.February 2025, 1:19:55 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Tu 18.February 2025, 11:11:15 am
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include "sources/gfx/renderer/include/renderer_manager.h"
#include "sources/utils/include/logger.h"

namespace GFX
{
    namespace Render
    {
        RendererManager::RendererManager(SDL_Window* aWindow)
        {
            mRenderer = SDL_CreateRenderer(aWindow, -1, SDL_RENDERER_ACCELERATED);
            if(!mRenderer)
            {
                Utils::LOG::Logger::error("SDL2 Error: Failed to create renderer\nSDL Error: " + std::string(SDL_GetError()) + "\n");
            }
        }

        RendererManager::~RendererManager()
        {
            if(mRenderer)
            {
                SDL_DestroyRenderer(mRenderer);
            }
        }

        SDL_Renderer* RendererManager::getRenderer() const
        {
            return mRenderer;
        }

        void RendererManager::addGuiElement(std::shared_ptr<UI::ELEM::GuiElementBase> element)
        {
            mGuiElements.push_back(element);
        }

        void RendererManager::renderAllElements()
        {
            SDL_RenderClear(mRenderer);
            for(auto& element : mGuiElements)
            {
                if(element->isVisible())
                {
                    element->render(mRenderer);
                }
            }
            SDL_RenderPresent(mRenderer);
        }

        void RendererManager::updateAllElements()
        {
            for(auto& element : mGuiElements)
            {
                element->update();
            }
        }
    }
}