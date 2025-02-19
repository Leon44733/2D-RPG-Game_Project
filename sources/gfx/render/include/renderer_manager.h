/**
 * ###############################################################################
 *  File: renderer_manager.h
 *  Project: 2D-RPG-Game
 *  Created Date: Su 09.February 2025, 12:47:07 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Tu 18.February 2025, 3:23:34 pm
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

namespace GFX
{
    namespace Render
    {
        class RendererManager
        {
            public:
                RendererManager(SDL_Window*);
                ~RendererManager();
                
                void addRenderable(std::shared_ptr<IRenderable>);
                void renderAll();
                void updateAll();
                
                SDL_Renderer* getRenderer() const;
                GuiRenderer& getGuiRenderer();

            private:
                SDL_Renderer* mRenderer;
                std::vector<std::shared_ptr<IRenderable>> mRenderables;
                GuiRenderer mGuiRenderer;
        };
    }
}

#endif // RENDERER_MANAGER_H