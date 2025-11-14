/**
 * ###############################################################################
 *  File: renderer_manager.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Su 09.February 2025, 1:19:55 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 14.November 2025, 11:34:46 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include "gfx/render/include/renderer_manager.h"
#include "gfx/render/include/renderer_factory.h"
#include "utils/include/logger.h"

namespace gfx
{
  namespace render
  {
    RendererManager::RendererManager(SDL_Window* aWindow)
      : mRenderer(SDL_CreateRenderer(aWindow, -1, SDL_RENDERER_ACCELERATED))
    {
      if(!mRenderer)
      {
        utils::log::Logger::error("SDL2 Error: Failed to create renderer\nSDL Error: " + std::string(SDL_GetError()) + "\n");
      }

      // initialize renderers
      mBgRenderer = RendererFactory::createRenderer(RendererType::BACKGROUND, mRenderer);
      mGuiRenderer = RendererFactory::createRenderer(RendererType::GUI, mRenderer);
      mCharRenderer = RendererFactory::createRenderer(RendererType::CHARACTER, mRenderer);
    }

    RendererManager::~RendererManager()
    {
      // free renderer
      if(mRenderer)
      {
        SDL_DestroyRenderer(mRenderer);
      }
    }

    SDL_Renderer* RendererManager::getRenderer() const
    {
      return mRenderer;
    }

    IRenderer& RendererManager::getBgRenderer()
    {
      return *mBgRenderer;
    }

    void RendererManager::addBgElement(std::shared_ptr<Renderable> aElem, std::string aName)
    {
      mBgElements[aName] = aElem;
    }

    Renderable& RendererManager::getBgElement(std::string aName)
    {
      return *mBgElements[aName];
    }

    void RendererManager::renderBgElement(std::string aName, std::shared_ptr<ICamera> aCamera)
    {
      SDL_RenderClear(mRenderer);
      if(mBgElements.find(aName) == mBgElements.end())
      {
        utils::log::Logger::error("Background element not found with name: " + aName);
      }

      if(mBgElements[aName]->isVisible())
      {
        mBgElements[aName]->render(*this, aCamera);
      }
    }

    IRenderer& RendererManager::getGuiRenderer() const
    {
      return *mGuiRenderer;
    }

    void RendererManager::addGuiElement(std::shared_ptr<Renderable> aElem)
    {
      mGuiElements.push_back(aElem);
    }

    void RendererManager::renderAllGuiElem()
    {
      // render all renderable elements
      for(auto& element : mGuiElements)
      {
        if(element->isVisible())
        {
          element->render(*this);
        }
      }
    }

    IRenderer& RendererManager::getCharRenderer() const
    {
      return *mCharRenderer;
    }

    void RendererManager::addCharElement(std::shared_ptr<Renderable> aElem, std::string aName)
    {
      mCharElements[aName] = aElem;
    }

    Renderable& RendererManager::getCharElement(std::string aName)
    {
      return *mCharElements[aName];
    }

    void RendererManager::renderCharElement(std::string aName)
    {
      if(mCharElements.find(aName) == mCharElements.end())
      {
        utils::log::Logger::error("Character element not found with name: " + aName);
      }

      if(mCharElements[aName]->isVisible())
      {
        mCharElements[aName]->render(*this);
      }
    }
  }
}