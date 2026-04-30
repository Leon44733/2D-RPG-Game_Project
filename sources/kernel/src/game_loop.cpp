/**
 * ###############################################################################
 *  File: game_loop.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 31.January 2025, 7:10:52 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Th 30.April 2026, 10:34:13 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include <SDL2/SDL.h>

#include "kernel/include/game_loop.h"
#include "kernel/include/camera.h"

#include "gfx/render/include/renderer_manager.h"
#include "gfx/texture/include/texture_manager.h"
#include "gfx/render/include/renderable.h"

#include "ui/window/include/window.h"

namespace kernel
{
  GameLoop::GameLoop(std::shared_ptr<ui::Window> apSDLWindow, std::unique_ptr<gfx::render::RendererManager> apRManager, std::unique_ptr<gfx::texture::TextureManager> apTManager)
    : mpSDLWindow(apSDLWindow),
      mpRManager(std::move(apRManager)),
      mpTManager(std::move(apTManager))
  {
    // add player camera
    mpCamera = std::make_shared<Camera>(apSDLWindow.get()->getWidth(), apSDLWindow.get()->getHeight(), mpRManager->getBgElement("Background_1").getElementWidth(), mpRManager->getBgElement("Background_1").getElementHeight());
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
    SDL_RenderClear(mpRManager->getRenderer());
    mpRManager->renderBgElement("Background_1", mpCamera);
    mpRManager->renderAllGuiElements();
    mpRManager->renderCharElement("Player");

    // update key input
    mKeyInput.update();
    checkForInput();

    SDL_RenderPresent(mpRManager->getRenderer());
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

    mpCamera->update(moveX, moveY);

    SDL_Delay(1);
  }
}