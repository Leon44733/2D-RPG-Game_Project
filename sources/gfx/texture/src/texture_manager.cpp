/**
 * ###############################################################################
 *  File: texture_manager.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Tu 04.February 2025, 10:40:37 am
 *  Author: lbarwe
 *  -----
 *  Last Modified: We 15.October 2025, 10:10:08 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include <SDL_image.h>

#include "gfx/texture/include/texture_manager.h"
#include "utils/include/logger.h"

namespace gfx
{
  namespace texture
  {
    TextureManager::TextureManager() {}

    TextureManager::~TextureManager()
    {
      // free all textures in cache
      for(auto& texture : mTextureCache)
      {
        SDL_DestroyTexture(texture.second);
      }
      clearCache();
    }

    bool TextureManager::load(const std::string& aFilePath, const std::string& aTextureId, SDL_Renderer* aRenderer)
    {
      // load texture from file
      SDL_Texture* texture = IMG_LoadTexture(aRenderer, aFilePath.c_str());
      if(!texture)
      {
        utils::log::Logger::error("SDL2 Error: Failed to load texture.\nSDL Error: " + std::string(SDL_GetError()) + "\n");
        return false;
      }

      // save texture in unordered map
      mTextureCache[aTextureId] = texture;
      return true;
    }

    SDL_Texture* TextureManager::getTexture(const std::string& aTextureId) const
    {
      // search for texture in cache and return it
      auto it = mTextureCache.find(aTextureId);
      if(it != mTextureCache.end())
      {
        return it->second;
      }
      utils::log::Logger::warning("Texture not found with ID: " + aTextureId);
      return nullptr;
    }

    bool TextureManager::releaseTexture(const std::string& aTextureId)
    {
      // search for texture in cache and release it
      auto it = mTextureCache.find(aTextureId);
      if(it != mTextureCache.end())
      {
        SDL_DestroyTexture(it->second);
        mTextureCache.erase(it);
        return true;
      }
      utils::log::Logger::warning("Texture with ID '" + aTextureId + "' not found.");
      return false;
    }

    void TextureManager::clearCache()
    {
      // free all textures in cache
      for(auto& texture : mTextureCache)
      {
        SDL_DestroyTexture(texture.second);
      }
      mTextureCache.clear();
      utils::log::Logger::info("Texture cache cleared.");
    }
  }
}