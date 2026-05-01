/**
 * ###############################################################################
 *  File: texture_manager.h
 *  Project: 2D-RPG-Game
 *  Created Date: We 29.January 2025, 9:34:49 am
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 01.May 2026, 6:55:26 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SDL3/SDL.h>
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
       *        This function destroys all textures in the cache and clears the cache.
       */
      ~TextureManager();

      /**
       * @brief Load texture from file and save it in the cache.
       * @param arFilePath path to the image file
       * @param arTextureId texture identifier
       * @param apRenderer renderer to create texture
       * @return true if loading was successful, false otherwise.
       */
      bool load(const std::string& arFilePath, const std::string& arTextureId, SDL_Renderer* apRenderer);

      /**
       * @brief Get texture from cache.
       * @param arTextureId texture identifier
       * @return texture from cache or nullptr if not found.
       */
      SDL_Texture* getTexture(const std::string& arTextureId) const;

      /**
       * @brief Release texture from cache.
       * @param arTextureId texture identifier
       * @return true if texture was released, false otherwise.
       */
      bool releaseTexture(const std::string& arTextureId);

      /**
       * @brief Destroy all textures in the cache and clear the cache.
       */
      void clearCache();

    private:
      std::unordered_map<std::string, SDL_Texture*> mTextureCache; // texture cache
    };
  }
}

#endif // TEXTURE_MANAGER_H