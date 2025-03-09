/**
 * ###############################################################################
 *  File: background_renderer.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: We 05.March 2025, 2:28:02 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 08.March 2025, 4:47:55 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */
 
#include "gfx/render/include/background_renderer.h"

namespace gfx
{
  namespace render
  {
    BackgroundRenderer::BackgroundRenderer(SDL_Renderer* aRenderer) : mRenderer(aRenderer) {}
    BackgroundRenderer::~BackgroundRenderer() {}

    void BackgroundRenderer::render(const Renderable& aElem, std::shared_ptr<ICamera> aCamera)
    {
        // move background based on camera position 
        int backgroundPosX = 0 - aCamera->getPos().x;
        int backgroundPosY = 0 - aCamera->getPos().y;

        // render texture at position
        SDL_Rect destRect = { backgroundPosX, backgroundPosY, aElem.getElementWidth(), aElem.getElementHeigth() };
        SDL_RenderCopy(mRenderer, aElem.getTexture(), nullptr, &destRect);
    }
  }
}