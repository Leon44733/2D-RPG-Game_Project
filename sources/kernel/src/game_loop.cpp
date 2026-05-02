/**
 * ###############################################################################
 *  File: game_loop.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 31.January 2025, 7:10:52 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Su 03.May 2026, 12:39:03 am
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include <SDL3/SDL.h>

#include "kernel/include/game_loop.h"
#include "kernel/input/include/input_manager.h"
#include "platform/inlcude/window.h"

namespace kernel
{
  GameLoop::GameLoop(utils::log::Logger& arLogger)
    : mrLogger(arLogger)
  {}

  GameLoop::~GameLoop() {}

  void GameLoop::run()
  {
    bool running = true;
    input::InputManager input_manager;
    SDL_Event event;

    while(running)
    {
      // open window until user closes it
      while(SDL_PollEvent(&event))
      {
        if(event.type == SDL_EVENT_QUIT)
        {
          running = false;
          mrLogger.info("Quit event received. Exit game loop.");
        }

        input_manager.processEvent(event);
      }
    }
  }
}