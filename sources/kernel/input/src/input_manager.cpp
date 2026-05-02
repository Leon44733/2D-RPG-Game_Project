/**
 * ###############################################################################
 *  File: input_manager.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 02.May 2026, 11:26:36 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Su 03.May 2026, 12:48:04 am
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2026 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include "kernel/input/include/input_manager.h"

kernel::input::InputManager::InputManager()
  : mpState(SDL_GetKeyboardState(nullptr))
{}

kernel::input::InputManager::~InputManager()
{}

void kernel::input::InputManager::update()
{
  SDL_PumpEvents();
  mpState = SDL_GetKeyboardState(nullptr);
}

void kernel::input::InputManager::processEvent(const SDL_Event& aEvent)
{
  if(aEvent.type == SDL_EVENT_KEY_DOWN)
  {
    // ToDo: Handle key down events
  }
  else if(aEvent.type == SDL_EVENT_KEY_UP)
  {
    // ToDo: Handle key up events
  }
}