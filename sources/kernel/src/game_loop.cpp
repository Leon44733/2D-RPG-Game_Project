/**
 * ###############################################################################
 *  File: game_loop.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 31.January 2025, 7:10:52 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: We 05.March 2025, 4:27:23 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include <SDL.h>
#include <iostream>

#include "kernel/include/game_loop.h"
#include "kernel/include/camera.h"

namespace kernel
{
    GameLoop::GameLoop(std::shared_ptr<ui::Window> aSDLWindow, std::unique_ptr<gfx::render::RendererManager> aRManager, std::unique_ptr<gfx::texture::TextureManager> aTManager)  :
        mSDLWindow(aSDLWindow),
        mRManager(std::move(aRManager)),
        mTManager(std::move(aTManager)),
        mLastTime(SDL_GetTicks())
        {
            // add player camera
            mCamera = Camera(aSDLWindow.get()->getWidth(), aSDLWindow.get()->getHeight(), 2000, 2000);

            // create player character
            SDL_Texture* playerTexture = mTManager->getTexture("Player");
            // 100.0f
            mPlayer = std::make_shared<entities::characters::PlayerCharacter>(0, 0, 1, playerTexture, mCamera);
            mRManager->addRenderable(mPlayer);
        }
        
    GameLoop::~GameLoop() {}

    void GameLoop::run()
    {
        bool running = true;
        SDL_Event event;

        while (running)
        {
            // open window until user closes it
            while (SDL_PollEvent(&event))
            {
                // check if user closes window
                if (event.type == SDL_QUIT)
                {
                    running = false;
                }
                handleEvents(); // TODO
            }

            update();
            render();
        }
    }

    void GameLoop::render()
    {
        mRManager->renderAll();
    }

    void GameLoop::update()
    {
        // adjustment of the rendering position by the camera
        int renderX = mPlayer->getXPos() - mCamera.getXPos();
        int renderY = mPlayer->getYPos() - mCamera.getYPos();

        mCamera.update(mPlayer->getXPos(), mPlayer->getYPos());

        mPlayer.get()->render(mPlayer->getTexture(), renderX, renderY, mPlayer->getWidth(), mPlayer->getHeight());
        mRManager->getBackgroundRenderer().render(backgroundTexture, -mCamera.getXPos(), -mCamera.getYPos());
        
        // calculate delta time
        Uint32 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - mLastTime) / 1000.0f;   // convert to seconds
        mLastTime = currentTime;

        // update key input
        mKeyInput.update();
        checkForInput(deltaTime);
    }
    
    void GameLoop::handleEvents()
    {
        // TODO: Handle events for the game
        // for example: on key press, on mouse click, etc. for starting a menu etc.
    }

    void GameLoop::checkForInput(float aDeltaTime)
    {
        if (mKeyInput.isKeyPressed(SDL_SCANCODE_W)) { mPlayer->moveUp(aDeltaTime); }
        if (mKeyInput.isKeyPressed(SDL_SCANCODE_S)) { mPlayer->moveDown(aDeltaTime); }
        if (mKeyInput.isKeyPressed(SDL_SCANCODE_A)) { mPlayer->moveLeft(aDeltaTime); }
        if (mKeyInput.isKeyPressed(SDL_SCANCODE_D)) { mPlayer->moveRight(aDeltaTime); }
    }
}