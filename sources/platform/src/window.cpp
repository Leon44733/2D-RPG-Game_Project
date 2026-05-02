/**
 * ###############################################################################
 *  File: window.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 02.May 2026, 4:07:44 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 02.May 2026, 4:28:31 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2026 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include <iostream>
#include <SDL3_image/SDL_image.h>

#include "platform/inlcude/window.h"
#include "utils/include/logger.h"

namespace platform
{
  Window::Window(utils::log::Logger& arLogger)
    : mrLogger(arLogger), 
      mpSDLWindow(nullptr),
      mWidth(800), // ToDo: Remove default value for width later, when window size is set by config file or user input
      mHeight(300) // ToDo: Remove default value for height later, when window size is set by config file or user input
  {}

  Window::~Window()
  {
    if(mpSDLWindow)
    {
      // destroy SDL window
      SDL_DestroyWindow(mpSDLWindow);
      mpSDLWindow = nullptr;
    }
  }

  bool Window::init()
  {
    // create SDL window
    mpSDLWindow = SDL_CreateWindow(
        "SDL3 Window",
        mWidth,
        mHeight,
        0);

    if(!mpSDLWindow)
    {
      // error while trying to create window
      mrLogger.error("SDL3 Error: Failed to create window\nSDL Error: " + std::string(SDL_GetError()) + "\n");
      return false;
    }
    return true;
  }

  void Window::setSize(int aWidth, int aHeight)
  {
    mWidth = aWidth;
    mHeight = aHeight;
  }

  int Window::getWidth() const
  {
    return mWidth;
  }

  int Window::getHeight() const
  {
    return mHeight;
  }

  SDL_Window* Window::getSDLWindow() const
  {
    return mpSDLWindow;
  }
}