/**
 * ###############################################################################
 *  File: window.h
 *  Project: 2D-RPG-Game
 *  Created Date: Th 02.January 2025, 2:16:29 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: We 15.October 2025, 9:59:21 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>

namespace ui
{
  /**
   * @brief Window class for handling the window.
   */
  class Window
  {
  public:
    /**
     * @brief Construct new Window object.
     * Default window size is 800x300.
     */
    Window();

    /**
     * @brief Construct new Window object.
     * @param aWidth window width
     * @param aHight window height
     */
    Window(int aWidth, int aHeight);

    /**
     * @brief Destroy Window object.
     * This function calls destruct() function.
     */
    ~Window();

    /**
     * @brief Initialize window.
     * This includes initialization of SDL2 library and creation of window.
     * @return true if initialization was successful, false otherwise.
     */
    bool init();

    /**
     * @brief Destruct window.
     * Sdl_Quit() is called at the end.
     */
    void destruct();

    /**
     * @brief Set window size.
     * @param aWidth window width
     * @param aHeight window hight
     */
    void setSize(int aWidth, int aHeight);

    /**
     * @brief Get window width.
     * @return int window width
     */
    int getWidth() const;

    /**
     * @brief Get window height.
     * @return int window height
     */
    int getHeight() const;

    /**
     * @brief Get SDL window.
     * @return SDL_Window* sdl window
     */
    SDL_Window* getSDLWindow() const;

  private:
    SDL_Window* mSDLWindow; // sdl window
    int mWidth;             // window width. Default by constructor is 800
    int mHeight;            // window height. Default by constructor is 300
  };
}

#endif // WINDOW_H