/**
 * ###############################################################################
 *  File: game_loop.h
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 31.January 2025, 7:11:00 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 06.February 2026, 9:57:45 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include <memory>

#include "kernel/input/include/key_input.h"

namespace ui
{
  // forward declaration
  class Window;
}

namespace gfx::render
{
  // forward declarations
  class RendererManager;
  class ICamera;
}

namespace gfx::texture
{
  // forward declaration
  class TextureManager;
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
     * @param aSDLWindow shared pointer to window object
     * @param aRManager unique pointer to renderer manager object
     * @param aTManager unique pointer to texture manager object
     */
    GameLoop(std::shared_ptr<ui::Window> aSDLWindow, std::unique_ptr<gfx::render::RendererManager> aRManager, std::unique_ptr<gfx::texture::TextureManager> aTManager);

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
    /**
     * @brief Update and render all elements.
     */
    void updateAndRender();

    /**
     * @brief Check for input from the user.
     */
    void checkForInput();

    std::shared_ptr<ui::Window>                   mpSDLWindow; // shared pointer to window object
    std::unique_ptr<gfx::render::RendererManager> mpRManager;  // unique pointer to renderer manager object
    std::unique_ptr<gfx::texture::TextureManager> mpTManager;  // texture manager object
    std::shared_ptr<gfx::render::ICamera>         mpCamera;    // camera object
    input::KeyInput                               mKeyInput;   // key input object
  };
}

#endif // GAME_LOOP_H