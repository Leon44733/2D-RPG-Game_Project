/**
 * ###############################################################################
 *  File: game_loop.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 31.January 2025, 7:10:52 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: We 15.October 2025, 10:06:58 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include <SDL.h>

#include "kernel/include/game_loop.h"
#include "kernel/include/camera.h"

namespace kernel
{
  GameLoop::GameLoop(std::shared_ptr<ui::Window> aSDLWindow, std::unique_ptr<gfx::render::RendererManager> aRManager, std::unique_ptr<gfx::texture::TextureManager> aTManager)
    : mSDLWindow(aSDLWindow),
      mRManager(std::move(aRManager)),
      mTManager(std::move(aTManager))
  {
    // add player camera
    mCamera = std::make_shared<Camera>(aSDLWindow.get()->getWidth(), aSDLWindow.get()->getHeight(), mRManager->getBgElement("Background_1").getElementWidth(), mRManager->getBgElement("Background_1").getElementHeight());
  }

  GameLoop::~GameLoop() {}

  void GameLoop::run()
  {
    bool running = true;
    SDL_Event event;

    while(running)
    {
      // open window until user closes it
      while(SDL_PollEvent(&event))
      {
        // check if user closes window
        if(event.type == SDL_QUIT)
        {
          running = false;
        }
      }

      updateAndRender();
    }
  }

  void GameLoop::updateAndRender()
  {
    // render all elements in window
    SDL_RenderClear(mRManager->getRenderer());
    mRManager->renderBgElement("Background_1", mCamera);
    mRManager->renderAllGuiElem();
    mRManager->renderCharElement("Player");

    // update key input
    mKeyInput.update();
    checkForInput();

    SDL_RenderPresent(mRManager->getRenderer());
  }

  void GameLoop::checkForInput()
  {
    int moveX = 0, moveY = 0;
    const int speed = 1; // movement speed

        // check for pressed keys
        if(mKeyInput.isKeyPressed(SDL_SCANCODE_W)) { moveY -= speed; }
        if(mKeyInput.isKeyPressed(SDL_SCANCODE_S)) { moveY += speed; }
        if(mKeyInput.isKeyPressed(SDL_SCANCODE_A)) { moveX -= speed; }
        if(mKeyInput.isKeyPressed(SDL_SCANCODE_D)) { moveX += speed; }

    mCamera->update(moveX, moveY);

    SDL_Delay(1);
  }
}