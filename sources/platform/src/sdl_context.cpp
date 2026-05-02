/**
 * ###############################################################################
 *  File: sdl_context.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 02.May 2026, 3:38:22 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 02.May 2026, 4:39:05 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2026 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include <SDL3/SDL.h>
#include <string>

#include "platform/inlcude/sdl_context.h"
#include "utils/include/logger.h"

platform::SDLContext::SDLContext(utils::log::Logger& arLogger)
  : mrLogger(arLogger)
{}

platform::SDLContext::~SDLContext()
{
  SDL_Quit(); // quit SDL3 library
}

bool platform::SDLContext::init()
{
  // Initialize SDL3 library
  if(!SDL_Init(SDL_INIT_VIDEO)) // ToDo: Add other flags later (e.g. | SDL_INIT_AUDIO)
  {
    mrLogger.error("SDL3 Error: Failed to initialize the SDL3 library\nSDL Error: " + std::string(SDL_GetError()) + "\n");
    return false;
  }
  return true;
}