/**
 * ###############################################################################
 *  File: renderer_manager.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Su 09.February 2025, 1:19:55 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 22.February 2025, 1:37:48 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include "gfx/render/include/renderer_manager.h"
#include "gfx/render/include/i_renderable.h"
#include "utils/include/logger.h"

namespace gfx
{
    namespace render
    {
        RendererManager::RendererManager(SDL_Window* aWindow) :
            mRenderer(SDL_CreateRenderer(aWindow, -1, SDL_RENDERER_ACCELERATED)),
            mGuiRenderer(mRenderer)
        {
            if(!mRenderer)
            {
                utils::log::Logger::error("SDL2 Error: Failed to create renderer\nSDL Error: " + std::string(SDL_GetError()) + "\n");
            }
        }

        RendererManager::~RendererManager()
        {
            // free renderer
            if(mRenderer)
            {
                SDL_DestroyRenderer(mRenderer);
            }
        }
        
        SDL_Renderer* RendererManager::getRenderer() const
        {
            return mRenderer;
        }

        GuiRenderer& RendererManager::getGuiRenderer()
        {
            return mGuiRenderer;
        }

        void RendererManager::addRenderable(std::shared_ptr<IRenderable> aElement)
        {
            mRenderables.push_back(aElement);
        }

        void RendererManager::renderAll()
        {
            // render all renderable elements
            SDL_RenderClear(mRenderer);
            for(auto& element : mRenderables)
            {
                if(element->isVisible())
                {
                    element->render(*this);
                }
            }
            SDL_RenderPresent(mRenderer);
        }

        void RendererManager::updateAll()
        {
            // update all renderable elements
            for(auto& element : mRenderables)
            {
                element->update();
            }
        }
    }
}