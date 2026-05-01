/**
 * ###############################################################################
 *  File: renderer_manager.h
 *  Project: 2D-RPG-Game
 *  Created Date: Su 09.February 2025, 12:47:07 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 01.May 2026, 6:55:26 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef RENDERER_MANAGER_H
#define RENDERER_MANAGER_H

#include <SDL3/SDL.h>
#include <vector>
#include <memory>
#include <unordered_map>

namespace gfx
{
  namespace render
  {
    // forward declarations
    class Renderable;
    class IRenderer;
    class ICamera;

    /**
     * @brief RendererManager class for managing the renderers.
     */
    class RendererManager
    {
    public:
      /**
       * @brief Construct new RendererManager object.
       * @param apWindow SDL window
       */
      RendererManager(SDL_Window* apWindow);
      
      /**
       * @brief Destroy RendererManager object.
       * This function also destroys the renderer.
       */
      ~RendererManager();
      
      /**
       * @brief Get SDL renderer.
       * @return sdl renderer pointer
       */
      SDL_Renderer* getRenderer() const;
      
      /**
       * @brief Get BackgroundRenderer object.
       * @return background renderer reference
       */
      IRenderer& getBgRenderer();
      
      /**
       * @brief Add renderable background object to unordered map.
       * @param apElem shared pointer to renderable element
       * @param aName identifier name of renderable background
       */
      void addBgElement(std::shared_ptr<Renderable> apElem, std::string aName);
      
      /**
       * @brief Get background element from unordered map.
       * @return renderable background reference
       */
      Renderable& getBgElement(std::string aName);
      
      /**
       * @brief Render background element.
       * @param aName identifier name of renderable background
       * @param aCamera camera
       */
      void renderBgElement(std::string aName, std::shared_ptr<ICamera> aCamera);
    
      /**
       * @brief Get GuiRenderer object.
       * @return gui renderer reference
       */
      IRenderer& getGuiRenderer() const;
      
      /**
       * @brief Add renderable element to vector.
       * @param apElem shared pointer to renderable element
       */
      void addGuiElement(std::shared_ptr<Renderable> apElem);

      /**
       * @brief Render all renderable elements in the renderables vector.
       *        It also clears the renderer before rendering.
       */
      void renderAllGuiElements();

      /**
       * @brief Get CharacterRenderer object.
       * @return character renderer reference
       */
      IRenderer& getCharRenderer() const;

      /**
       * @brief Add renderable character element to unordered map.
       * @param apElem shared pointer to renderable element
       * @param aName identifier name of renderable character
       */
      void addCharElement(std::shared_ptr<Renderable> apElem, std::string aName);

      /**
       * @brief Get character element from unordered map.
       * @return renderable character reference
       */
      Renderable& getCharElement(std::string aName);

      /**
       * @brief Render character element.
       * @param aName identifier name of renderable character
       */
      void renderCharElement(std::string aName);

    private:
      SDL_Renderer*                                                mpRenderer;     // sdl renderer
      std::unique_ptr<IRenderer>                                   mpBgRenderer;   // background renderer
      std::unique_ptr<IRenderer>                                   mpGuiRenderer;  // gui renderer
      std::unique_ptr<IRenderer>                                   mpCharRenderer; // character renderer
      std::vector<std::shared_ptr<Renderable>>                     mGuiElements;   // vector containing gui elements
      std::unordered_map<std::string, std::shared_ptr<Renderable>> mBgElements;    // map of background elements
      std::unordered_map<std::string, std::shared_ptr<Renderable>> mCharElements;  // map of character elements
    };
  }
}

#endif // RENDERER_MANAGER_H