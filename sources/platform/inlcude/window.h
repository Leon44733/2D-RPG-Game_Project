/**
 * ###############################################################################
 *  File: window.h
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 02.May 2026, 4:07:54 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 02.May 2026, 4:22:52 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2026 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef WINDOW_H
#define WINDOW_H

#include <SDL3/SDL.h>

namespace utils::log
{
  //Forward declaration
  class Logger;
}

namespace platform
{
  /**
   * @brief Window class for handling the window.
   */
  class Window
  {
  public:
    /**
     * @brief Construct new Window object.
     */
    Window(utils::log::Logger& arLogger);

    /**
     * @brief Destroy Window object.
     */
    ~Window();

    /**
     * @brief Initialize window.
     * @return true if initialization was successful, false otherwise.
     */
    bool init();

    /**
     * @brief Set window size.
     * @param aWidth window width
     * @param aHeight window height
     */
    void setSize(int aWidth, int aHeight);

    /**
     * @brief Get window width.
     * @return window width
     */
    int getWidth() const;

    /**
     * @brief Get window height.
     * @return window height
     */
    int getHeight() const;

    /**
     * @brief Get SDL window.
     * @return sdl window pointer
     */
    SDL_Window* getSDLWindow() const;

  private:
    Window() = delete;                         // prevent default construction
    Window(const Window&) = delete;            // prevent copy-construction
    Window& operator=(const Window&) = delete; // prevent assignment

    utils::log::Logger& mrLogger;    // reference to the logger instance
    SDL_Window*         mpSDLWindow; // sdl window
    int                 mWidth;      // window width
    int                 mHeight;     // window height
  };
}

#endif // WINDOW_H