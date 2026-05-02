/**
 * ###############################################################################
 *  File: main.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Th 26.December 2024, 3:25:20 am
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 02.May 2026, 4:44:04 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2024 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#define SDL_MAIN_HANDLED

#include "platform/inlcude/sdl_context.h"
#include "platform/inlcude/window.h"
#include "utils/include/logger.h"

int main()
{
  utils::log::Logger logger;

  platform::SDLContext sdlContext(logger);
  if(!sdlContext.init())
    return -1;

  platform::Window window(logger);
  if(!window.init())
    return -1;
  else
    logger.info("Window initialized successfully.\n");
}