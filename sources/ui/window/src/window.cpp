/**
 * ###############################################################################
 *  File: window.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Th 02.January 2025, 2:16:01 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Th 30.April 2026, 10:52:24 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include <iostream>
#include <SDL2/SDL_image.h>

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
    // Initialize SDL2 library
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
      // error while trying to initialize SDL2 library
      // TODO: utils::log::Logger::error("SDL2 Error: Failed to initialize the SDL2 library\nSDL Error: " + std::string(SDL_GetError()) + "\n");
      std::cout << "SDL2 Error: Failed to initialize the SDL2 library\nSDL Error: " + std::string(SDL_GetError()) + "\n";
      return false;
    }

    // Initialize SDL_image library
    if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
      // error while trying to initialize SDL_image library
      // TODO: utils::log::Logger::error("SDL2 Error: Failed to initialize the SDL_image library\nSDL Error: " + std::string(SDL_GetError()) + "\n");
      return false;
    }

    // create SDL window
    mpSDLWindow = SDL_CreateWindow(
        "SDL2 Window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        mWidth,
        mHeight,
        SDL_WINDOW_SHOWN);

    if(!mpSDLWindow)
    {
      // error while trying to create window
      // TODO: utils::log::Logger::error("SDL2 Error: Failed to create window\nSDL Error: " + std::string(SDL_GetError()) + "\n");
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

    IMG_Quit(); // quit SDL_image library
    SDL_Quit(); // quit SDL2 library
  }
}