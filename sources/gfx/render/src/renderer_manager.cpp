/**
 * ###############################################################################
 *  File: renderer_manager.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Su 09.February 2025, 1:19:55 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 01.May 2026, 7:51:04 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include "gfx/render/include/renderer_manager.h"
#include "gfx/render/include/renderer_factory.h"
#include "gfx/render/include/renderable.h"
#include "gfx/render/include/i_renderer.h"

#include "utils/include/logger.h"

namespace gfx
{
  namespace render
  {
    RendererManager::RendererManager(SDL_Window* apWindow)
      : mpRenderer(SDL_CreateRenderer(apWindow, NULL))
    {
      if(!mpRenderer)
      {
        // TODO: utils::log::Logger::error("Failed to create renderer\nSDL Error: " + std::string(SDL_GetError()) + "\n");
      }

      // initialize renderers
      mpBgRenderer = RendererFactory::createRenderer(RendererType::BACKGROUND, mpRenderer);
      mpGuiRenderer = RendererFactory::createRenderer(RendererType::GUI, mpRenderer);
      mpCharRenderer = RendererFactory::createRenderer(RendererType::CHARACTER, mpRenderer);
    }

    RendererManager::~RendererManager()
    {
      // free renderer
      if(mpRenderer)
      {
        SDL_DestroyRenderer(mpRenderer);
      }
    }

    SDL_Renderer* RendererManager::getRenderer() const
    {
      return mpRenderer;
    }

    IRenderer& RendererManager::getBgRenderer()
    {
      return *mpBgRenderer;
    }

    void RendererManager::addBgElement(std::shared_ptr<Renderable> apElem, std::string aName)
    {
      mBgElements[aName] = apElem;
    }

    Renderable& RendererManager::getBgElement(std::string aName)
    {
      return *mBgElements[aName];
    }

    void RendererManager::renderBgElement(std::string aName, std::shared_ptr<ICamera> apCamera)
    {
      SDL_RenderClear(mpRenderer);
      if(mBgElements.find(aName) == mBgElements.end())
      {
        // TODO: utils::log::Logger::error("Background element not found with name: " + aName);
      }

      // render background element if visible
      if(mBgElements[aName]->isVisible())
      {
        mBgElements[aName]->render(*this, apCamera);
      }
    }

    IRenderer& RendererManager::getGuiRenderer() const
    {
      return *mpGuiRenderer;
    }

    void RendererManager::addGuiElement(std::shared_ptr<Renderable> apElem)
    {
      mGuiElements.push_back(apElem);
    }

    void RendererManager::renderAllGuiElements()
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
      return *mpCharRenderer;
    }

    void RendererManager::addCharElement(std::shared_ptr<Renderable> apElem, std::string aName)
    {
      mCharElements[aName] = apElem;
    }

    Renderable& RendererManager::getCharElement(std::string aName)
    {
      return *mCharElements[aName];
    }

    void RendererManager::renderCharElement(std::string aName)
    {
      if(mCharElements.find(aName) == mCharElements.end())
      {
        // TODO: utils::log::Logger::error("Character element not found with name: " + aName);
      }

      if(mCharElements[aName]->isVisible())
      {
        mCharElements[aName]->render(*this);
      }
    }
  }
}