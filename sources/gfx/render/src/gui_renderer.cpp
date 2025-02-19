/**
 * ###############################################################################
 *  File: gui_renderer.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Tu 18.February 2025, 2:12:45 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: We 19.February 2025, 9:59:42 am
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

 #include "gfx/render/include/gui_renderer.h"

 namespace GFX
 {
   namespace Render
   {
     GuiRenderer::GuiRenderer(SDL_Renderer* aRenderer) :mRenderer(aRenderer) {}
     GuiRenderer::~GuiRenderer() {}
 
     void GuiRenderer::render(SDL_Texture* aTexture, int x, int y, int aWidth, int aHeight)
     {
         SDL_Rect dstRect = { x, y, aWidth, aHeight };
         SDL_RenderCopy(mRenderer, aTexture, nullptr, &dstRect);
     }
   }
 }