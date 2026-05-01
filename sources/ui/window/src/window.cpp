/**
 * ###############################################################################
 *  File: window.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Th 02.January 2025, 2:16:01 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 01.May 2026, 8:55:24 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include <iostream>
#include <SDL3_image/SDL_image.h>

#include "ui/window/include/window.h"

#include "utils/include/logger.h"

namespace ui
{
  Window::Window() : mpSDLWindow(nullptr), mWidth(800), mHeight(300) {}

  Window::Window(int aWidth, int aHeight) : mpSDLWindow(nullptr)
  {
    mWidth = aWidth;
    mHeight = aHeight;
  }

  Window::~Window()
  {
    destruct();
  }

  bool Window::init()
  {
    // Initialize SDL3 library
    if(!SDL_Init(SDL_INIT_VIDEO))
    {
      // error while trying to initialize SDL3 library
      // TODO: utils::log::Logger::error("SDL3 Error: Failed to initialize the SDL3 library\nSDL Error: " + std::string(SDL_GetError()) + "\n");
      return false;
    }

    // create SDL window
    mpSDLWindow = SDL_CreateWindow(
        "SDL3 Window",
        mWidth,
        mHeight,
        0);

    if(!mpSDLWindow)
    {
      // error while trying to create window
      // TODO: utils::log::Logger::error("SDL3 Error: Failed to create window\nSDL Error: " + std::string(SDL_GetError()) + "\n");
      SDL_Quit();
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

  void Window::destruct()
  {
    if(mpSDLWindow)
    {
      // destroy window if it exists
      SDL_DestroyWindow(mpSDLWindow);
      mpSDLWindow = nullptr;
    }

    SDL_Quit(); // quit SDL3 library
  }
}