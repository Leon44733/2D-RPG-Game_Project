/**
 * ###############################################################################
 *  File: main.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Th 26.December 2024, 3:25:20 am
 *  Author: lbarwe
 *  -----
 *  Last Modified: Mo 10.March 2025, 2:30:34 pm
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
#include "ui/elements/include/background_element.h"
#include "entities/characters/include/player_character.h"

int main() 
{
    std::cout << "Hello World!" << std::endl;

    // create, configure and initialize window
    std::shared_ptr<ui::Window> window = std::make_shared<ui::Window>(640, 360);
    std::shared_ptr<ui::Window> window = std::make_shared<ui::Window>(1920, 1080);
    if(!window->init())
    {
        window->destruct();
        utils::log::Logger::error("Could not initialize window");
        return -1;
    }

    // Initialize RendererManager with the window's renderer
    std::unique_ptr<gfx::render::RendererManager> rManager = std::make_unique<gfx::render::RendererManager>(window->getSDLWindow());

    // Initialize TextureManager and load texture
    std::unique_ptr<gfx::texture::TextureManager> tManager = std::make_unique<gfx::texture::TextureManager>();

    //================= For Live Demo Presentation =================
    tManager->load("assets/images/Background_2000x2000.png", "Background", rManager->getRenderer());
    tManager->load("assets/images/Player_Character.png", "Player", rManager->getRenderer());

    // tManager->load("assets/images/Dortmund-R-scaled.png", "Background", rManager->getRenderer());
    // tManager->load("assets/images/Heli.png", "Player", rManager->getRenderer());
    //================= For Live Demo Presentation =================
    
    tManager->load("assets/images/Hotbar.png", "Hotbar", rManager->getRenderer());
    tManager->load("assets/images/Health_Bar.png", "HealthBar", rManager->getRenderer());
    tManager->load("assets/images/Mana_Bar.png", "ManaBar", rManager->getRenderer());
    
    // Create a GUI element using the texture from the TextureManager
    SDL_Texture* hotBarTexture = tManager->getTexture("Hotbar");
    SDL_Texture* healthBarTexture = tManager->getTexture("HealthBar");
    SDL_Texture* manaBarTexture = tManager->getTexture("ManaBar");
    
    // Create a background element
    SDL_Texture* bgTexture = tManager->getTexture("Background");
    std::shared_ptr<ui::elem::BackgroundElement> bgElem = std::make_shared<ui::elem::BackgroundElement>(bgTexture);
    
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
    
    // TODO: Only for static background 
    // std::shared_ptr<ui::elem::TextureElement> bgTextureElem = std::make_shared<ui::elem::TextureElement>(bgTexture);
    // rManager->addGuiRenderable(bgTextureElem);
    
    rManager->addGuiRenderable(hotBarElem);
    rManager->addGuiRenderable(healthBarElem);
    rManager->addGuiRenderable(manaBarElem);
    rManager->addBgRenderable(bgElem, "Background_1");

    // create player character
    SDL_Texture* playerTexture = tManager->getTexture("Player");
    std::shared_ptr<entities::characters::PlayerCharacter> playerElem = std::make_shared<entities::characters::PlayerCharacter>(288, 148, playerTexture);
    rManager->addCharRenderable(playerElem, "Player");
    
    // Initialize and run the game loop
    kernel::GameLoop gameLoop(window, std::move(rManager), std::move(tManager));
    gameLoop.run();

    // Destruct window
    window->destruct();
    return 0;
}