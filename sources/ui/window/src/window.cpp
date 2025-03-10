/**
 * ###############################################################################
 *  File: window.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Th 02.January 2025, 2:16:01 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Mo 03.March 2025, 11:58:02 am
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include <iostream>
#include <SDL_image.h>

#include "ui/window/include/window.h"
#include "utils/include/logger.h"

namespace ui
{
    Window::Window() : mSDLWindow(nullptr), mWidth(800), mHeight(300) {}

    Window::Window(int aWidth, int aHeight) : mSDLWindow(nullptr)
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
            utils::log::Logger::error("SDL2 Error: Failed to initialize the SDL2 library\nSDL Error: " + std::string (SDL_GetError()) + "\n");
            return false;
        }

        // Initialize SDL_image library
        if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
        {
            // error while trying to initialize SDL_image library
            utils::log::Logger::error("SDL2 Error: Failed to initialize the SDL_image library\nSDL Error: " + std::string( SDL_GetError()) + "\n");
            return false;
        }

        // create SDL window
        mSDLWindow = SDL_CreateWindow(
            "SDL2 Window",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            mWidth,
            mHeight,
            SDL_WINDOW_SHOWN
            );
            
        if(!mSDLWindow)
        {
            // error while trying to create window
            utils::log::Logger::error("SDL2 Error: Failed to create window\nSDL Error: " + std::string (SDL_GetError()) + "\n");
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
        return mSDLWindow;
    }

    void Window::destruct()
    {
        if(mSDLWindow)
        {
            // destroy window if it exists
            SDL_DestroyWindow(mSDLWindow);
            mSDLWindow = nullptr;
        }
        
        IMG_Quit(); // quit SDL_image library
        SDL_Quit(); // quit SDL2 library
    }
}