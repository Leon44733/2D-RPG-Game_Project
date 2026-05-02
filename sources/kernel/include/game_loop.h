/**
 * ###############################################################################
 *  File: game_loop.h
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 31.January 2025, 7:11:00 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 02.May 2026, 5:01:12 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include "utils/include/logger.h"

namespace platform
{
  // forward declaration
  class Window;
}

namespace kernel
{
  /**
   * @brief GameLoop class for handling the game loop.
   */
  class GameLoop
  {
  public:
    /**
     * @brief Construct new GameLoop object.
     * @param arLogger reference to the logger instance
      *
     */
    GameLoop(utils::log::Logger& arLogger);

    /**
     * @brief Destroy GameLoop object.
     */
    ~GameLoop();

    /**
     * @brief Run the game loop.
     * This function handles events, updates game logic and renders the game.
     */
    void run();

  private:
    GameLoop() = delete;                           // prevent default construction
    GameLoop(const GameLoop&) = delete;            // prevent copy-construction
    GameLoop& operator=(const GameLoop&) = delete; // prevent assignment

    utils::log::Logger& mrLogger; // reference to the logger instance
  };
}

#endif // GAME_LOOP_H