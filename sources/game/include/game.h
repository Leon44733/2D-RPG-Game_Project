/**
 * ###############################################################################
 *  File: game.h
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 02.May 2026, 11:11:09 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 02.May 2026, 11:18:17 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2026 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef GAME_H
#define GAME_H

namespace game
{
  /**
   * @brief Game class for handling the main game logic.
    * This class initializes the game and runs the main game loop.
   */
  class Game
  {
  public:
    /**
     * @brief Construct new Game object.
     */
    Game();

    /**
     * @brief Destroy the Game object.
     */
    ~Game();

    /**
     * @brief Run the game.
     * This function initializes the game and runs the main game loop.
     */
    void run();
  };
}

#endif // GAME_H