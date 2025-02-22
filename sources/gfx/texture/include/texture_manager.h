/**
 * ###############################################################################
 *  File: texture_manager.h
 *  Project: 2D-RPG-Game
 *  Created Date: We 29.January 2025, 9:34:49 am
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 22.February 2025, 1:26:22 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SDL.h>
#include <string>
#include <unordered_map>

namespace gfx
{
  namespace texture
  {
    /**
     * @brief TextureManager class for managing textures.
     */
    class TextureManager
    {
        public:
        /**
         * @brief Construct new TextureManager object.
         */
          TextureManager();
          
          /**
           * @brief Destroy TextureManager object.
           * This function destroys all textures in the cache and clears the cache.
           */
          ~TextureManager();
          
          /**
           * @brief Load texture from file and save it in the cache.
           * @param aFilePath path to the image file
           * @param aTextureId texture identifier
           * @param aRenderer renderer to create texture
           * @return true if loading was successful, false otherwise.
           */
          bool load(const std::string& aFilePath, const std::string& aTextureId, SDL_Renderer* aRenderer);

          /**
           * @brief Get texture from cache.
           * @param aTextureId texture identifier
           * @return texture from cache or nullptr if not found.
           */
          SDL_Texture* getTexture(const std::string& aTextureId) const;
          
          /**
           * @brief Release texture from cache.
           * @param aTextureId texture identifier
           * @return true if texture was released, false otherwise.
           */
          bool releaseTexture(const std::string& aTextureId);

          /**
           * @brief Clear texture cache.
           * This function destroys all textures in the cache and clears the cache.
           */
          void clearCache();

        private:
          std::unordered_map<std::string, SDL_Texture*> mTextureCache;    // texture cache
    };
  }
}

#endif // TEXTURE_MANAGER_H