/**
 * ###############################################################################
 *  File: background_element.h
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 08.March 2025, 4:49:27 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Mo 10.March 2025, 1:28:10 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

 #ifndef BACKGROUND_ELEMENT_H
 #define BACKGROUND_ELEMENT_H
 
 #include <SDL.h>
 
 #include "gfx/render/include/renderer_manager.h"
 #include "gfx/render/include/i_camera.h"
 
 namespace ui
 {
   namespace elem
   {
     /**
      * @brief BackgroundElement class for rendering the background.
      * It inherits from Renderable class.
      */
     class BackgroundElement : public gfx::render::Renderable
     {
       public:
         /**
          * @brief Construct new BackgroundElement object.
          * @param aTexture background to render
          */
         BackgroundElement(SDL_Texture* aTexture);
         
         /**
          * @brief Destroy BackgroundElement object.
          */
         ~BackgroundElement();
 
        /**
          * @brief ATTENTION: This function is not needed for BackgroundElement.
          * @param aRenderer renderer manager
          */
         void render(gfx::render::RendererManager& aRenderer) override {};
         
         /**
          * @brief Render background element by passing the renderer manager and the camera.
          * @param aRenderer renderer manager
          * @param aCamera camera
          */
         void render(gfx::render::RendererManager& aRenderer, std::shared_ptr<gfx::render::ICamera> aCamera) override;
     };
   }
 }
 
 #endif // BACKGROUND_ELEMENT_H