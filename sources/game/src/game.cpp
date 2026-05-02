/**
 * ###############################################################################
 *  File: game.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 02.May 2026, 11:11:12 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 02.May 2026, 11:53:49 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2026 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include "game/include/game.h"

#include "platform/inlcude/sdl_context.h"
#include "platform/inlcude/window.h"
#include "kernel/include/game_loop.h"
#include "utils/include/logger.h"

game::Game::Game()
{}

game::Game::~Game()
{}

void game::Game::run()
{
  utils::log::Logger logger;

  platform::SDLContext sdlContext(logger);
  if(!sdlContext.init())
  {
    logger.error("Failed to initialize SDL context. Exiting game.");
    return;
  }

  platform::Window window(logger);
  if(!window.init())
  {
    logger.error("Failed to initialize window. Exiting game.");
    return;
  }
  else
  {
    logger.info("Window initialized successfully.");
  }

  kernel::GameLoop gameLoop(logger);
  gameLoop.run();
}