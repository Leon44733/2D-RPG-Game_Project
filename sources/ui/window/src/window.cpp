/**
 * ###############################################################################
 *  File: window.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Th 02.January 2025, 2:16:01 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 22.February 2025, 12:14:03 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include <iostream>

#include "ui/window/include/window.h"
#include "utils/include/logger.h"

namespace ui
{
    Window::Window() : mSDLWindow(nullptr), mWidth(300), mHight(800) {}
    Window::~Window()
    {
        destruct();
    }
    
    bool Window::init()
    {
        // initialize SDL2 library
        if(SDL_Init(SDL_INIT_VIDEO) != 0)
        { 
            // error while trying to initialize
            utils::log::Logger::error("SDL2 Error: Failed to initialize the SDL2 library\nSDL Error: " + std::string (SDL_GetError()) + "\n");
            return false;
        }

        // create SDL window
        mSDLWindow = SDL_CreateWindow(
            "SDL2 Window",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            mWidth,
            mHight,
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

    void Window::setSize(int aWidth, int aHight)
    {
        mWidth = aWidth;
        mHight = aHight;
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
        
        SDL_Quit();
    }
}