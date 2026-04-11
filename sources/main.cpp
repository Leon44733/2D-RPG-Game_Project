/**
 * ###############################################################################
 *  File: main.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Th 26.December 2024, 3:25:20 am
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 11.April 2026, 5:25:29 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2024 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#define SDL_MAIN_HANDLED

#include "gfx/texture/include/texture_manager.h"
#include "gfx/render/include/renderer_manager.h"
#include "ui/window/include/window.h"
#include "ui/elements/include/texture_element.h"
#include "ui/elements/include/background_element.h"
#include "entities/characters/include/player_character.h"
#include "kernel/include/game_loop.h"
#include "utils/include/logger.h"

int main()
{
  utils::log::Logger logger;
  logger.info("Starting game...");

  // Initialize window
  std::shared_ptr<ui::Window> window = std::make_shared<ui::Window>(640, 360); // ToDo: Window size will be changed later
  if(!window->init())
  {
    window->destruct();
    logger.error("Could not initialize window");
    return -1;
  }

  // Initialize RendererManager with the window's renderer
  std::unique_ptr<gfx::render::RendererManager> r_manager = std::make_unique<gfx::render::RendererManager>(window->getSDLWindow());

  // Initialize TextureManager and load texture
  std::unique_ptr<gfx::texture::TextureManager> t_manager = std::make_unique<gfx::texture::TextureManager>();

  //ToDo: Load textures in a more structured way, e.g. by using a config file or a resource manager class
  t_manager->load("assets/images/Background_2000x2000.png", "Background", r_manager->getRenderer());
  t_manager->load("assets/images/Player_Character.png", "Player", r_manager->getRenderer());
  t_manager->load("assets/images/Hotbar.png", "Hotbar", r_manager->getRenderer());
  t_manager->load("assets/images/Health_Bar.png", "Healthbar", r_manager->getRenderer());
  t_manager->load("assets/images/Mana_Bar.png", "Manabar", r_manager->getRenderer());

  // Create a GUI element using the texture from the TextureManager
  SDL_Texture* hotbar = t_manager->getTexture("Hotbar");
  SDL_Texture* healthbar = t_manager->getTexture("Healthbar");
  SDL_Texture* manabar = t_manager->getTexture("Manabar");

  // Create a background element
  SDL_Texture* bg_texture = t_manager->getTexture("Background");
  std::shared_ptr<ui::elem::BackgroundElement> bg_elem = std::make_shared<ui::elem::BackgroundElement>(bg_texture);

  std::shared_ptr<ui::elem::TextureElement> hotbar_elem = std::make_shared<ui::elem::TextureElement>(hotbar);
  int hotbar_x = (window->getWidth() - hotbar_elem->getElementWidth()) / 2; // center hotbar horizontally
  int hotbar_y = window->getHeight() - hotbar_elem->getElementHeight() - 10; // 10 pixels padding from the bottom
  hotbar_elem->setElementPos(hotbar_x, hotbar_y);

  std::shared_ptr<ui::elem::TextureElement> healthbar_elem = std::make_shared<ui::elem::TextureElement>(healthbar);
  int healthbar_x = 10; // 10 pixels padding from the left
  int healthbar_y = 10; // 10 pixels padding from the top
  healthbar_elem->setElementPos(healthbar_x, healthbar_y);

  std::shared_ptr<ui::elem::TextureElement> manabar_elem = std::make_shared<ui::elem::TextureElement>(manabar);
  int manabar_x = 10; // same x-position as healthbar
  int manabar_y = healthbar_y + healthbar_elem->getElementHeight() + 5; // healthbar_y + healthbar height + padding
  manabar_elem->setElementPos(manabar_x, manabar_y);

  r_manager->addGuiElement(hotbar_elem);
  r_manager->addGuiElement(healthbar_elem);
  r_manager->addGuiElement(manabar_elem);
  r_manager->addBgElement(bg_elem, "Background_1");

  // create player character
  SDL_Texture* player_texture = t_manager->getTexture("Player");
  std::shared_ptr<entities::characters::PlayerCharacter> player_elem = std::make_shared<entities::characters::PlayerCharacter>(288, 148, player_texture);
  r_manager->addCharElement(player_elem, "Player");

  // Initialize and run the game loop
  kernel::GameLoop game_loop(window, std::move(r_manager), std::move(t_manager));
  game_loop.run();

  // Destruct window
  window->destruct();
  return 0;
}