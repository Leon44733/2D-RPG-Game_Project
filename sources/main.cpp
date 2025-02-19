/**
 * ###############################################################################
 *  File: main.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Th 26.December 2024, 3:25:20 am
 *  Author: lbarwe
 *  -----
 *  Last Modified: Tu 18.February 2025, 3:57:59 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2024 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#define SDL_MAIN_HANDLED

#include <iostream>
#include <SDL.h>

#include "ui/window/include/window.h"
#include "kernel/include/game_loop.h"
#include "gfx/texture/include/texture_manager.h"
#include "utils/include/logger.h"
#include "gfx/render/include/renderer_manager.h"
#include "ui/elements/include/texture_element.h"

int main() 
{
    std::cout << "Hello World!" << std::endl;

    // create, configure and initialize window
    std::shared_ptr<UI::Window> window = std::make_shared<UI::Window>();
    window->setSize(640, 360);
    if(!window->init())
    {
        window->destruct();
        Utils::LOG::Logger::error("Could not initialize window");
        return -1;
    }

    // Initialize RendererManager with the window's renderer
    std::unique_ptr<GFX::Render::RendererManager> rManager = std::make_unique<GFX::Render::RendererManager>(window->getSDLWindow());

    // Initialize TextureManager and load a texture
    GFX::Texture::TextureManager tManager;
    tManager.load("assets/images/Test-Background.bmp", "Background", rManager->getRenderer());
    tManager.load("assets/images/GuiElement.bmp", "Test", rManager->getRenderer());

    // Create a GUI element using the texture from the TextureManager
    SDL_Texture* bgTexture = tManager.getTexture("Background");
    if (bgTexture == nullptr)
    {
        Utils::LOG::Logger::error("Could not load texture from TextureManager");
        window->destruct();
        return -1;
    }

    // Create a GUI element using the texture from the TextureManager
    SDL_Texture* texture = tManager.getTexture("Test");
    if (texture == nullptr)
    {
        Utils::LOG::Logger::error("Could not load texture from TextureManager");
        window->destruct();
        return -1;
    }

    // Create a GUI element and add it to the RendererManager
    std::shared_ptr<UI::ELEM::TextureElement> bgTextureElem = std::make_shared<UI::ELEM::TextureElement>(bgTexture);
    std::shared_ptr<UI::ELEM::TextureElement> textureElem = std::make_shared<UI::ELEM::TextureElement>(texture);
    rManager->addRenderable(bgTextureElem);
    rManager->addRenderable(textureElem);

    // Initialize and run the game loop
    Kernel::GameLoop gameLoop(window, std::move(rManager));
    gameLoop.run();

    window->destruct();
    return 0;
}