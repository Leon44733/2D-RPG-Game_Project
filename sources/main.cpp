/**
 * ###############################################################################
 *  File: main.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Th 26.December 2024, 3:25:20 am
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 01.March 2025, 2:22:37 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2024 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#define SDL_MAIN_HANDLED

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
    std::shared_ptr<ui::Window> window = std::make_shared<ui::Window>();
    window->setSize(640, 360);
    if(!window->init())
    {
        window->destruct();
        utils::log::Logger::error("Could not initialize window");
        return -1;
    }

    // Initialize RendererManager with the window's renderer
    std::unique_ptr<gfx::render::RendererManager> rManager = std::make_unique<gfx::render::RendererManager>(window->getSDLWindow());

    // Initialize TextureManager and load a texture
    gfx::texture::TextureManager tManager;
    tManager.load("assets/images/Background.png", "Background", rManager->getRenderer());
    tManager.load("assets/images/Hotbar.png", "Hotbar", rManager->getRenderer());
    tManager.load("assets/images/Health_Bar.png", "HealthBar", rManager->getRenderer());
    tManager.load("assets/images/Mana_Bar.png", "ManaBar", rManager->getRenderer());
    
    // Create a GUI element using the texture from the TextureManager
    SDL_Texture* bgTexture = tManager.getTexture("Background");
    SDL_Texture* hotBarTexture = tManager.getTexture("Hotbar");
    SDL_Texture* healthBarTexture = tManager.getTexture("HealthBar");
    SDL_Texture* manaBarTexture = tManager.getTexture("ManaBar");

    // Create a GUI element and add it to the RendererManager
    std::shared_ptr<ui::elem::TextureElement> bgElem = std::make_shared<ui::elem::TextureElement>(bgTexture);

    std::shared_ptr<ui::elem::TextureElement> hotBarElem = std::make_shared<ui::elem::TextureElement>(hotBarTexture);
    int hotBarX = (window->getWidth() - 192) / 2;   // center hotbar. 192 is the width of the hotbar
    int hotBarY = window->getHeight() - 32 - 10;    // center hotbar. 32 is the height of the hotbar
    hotBarElem->setElementPos(hotBarX, hotBarY);

    std::shared_ptr<ui::elem::TextureElement> healthBarElem = std::make_shared<ui::elem::TextureElement>(healthBarTexture);
    int healthBarX = 10;
    int healthBarY = 10;
    healthBarElem->setElementPos(healthBarX, healthBarY);

    std::shared_ptr<ui::elem::TextureElement> manaBarElem = std::make_shared<ui::elem::TextureElement>(manaBarTexture);
    int manaBarX = 10;
    int manaBarY = healthBarY + 32 + 5; // healthBarY + healthBarHeight + padding
    manaBarElem->setElementPos(manaBarX, manaBarY);
    
    rManager->addRenderable(bgElem);
    rManager->addRenderable(hotBarElem);
    rManager->addRenderable(healthBarElem);
    rManager->addRenderable(manaBarElem);

    // Initialize and run the game loop
    kernel::GameLoop gameLoop(window, std::move(rManager));
    gameLoop.run();

    // Destruct window
    window->destruct();
    return 0;
}