/**
 * ###############################################################################
 *  File: texture_manager.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Tu 04.February 2025, 10:40:37 am
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 06.February 2026, 9:12:14 pm
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
      clearCache();
    }

    bool TextureManager::load(const std::string& arFilePath, const std::string& arTextureId, SDL_Renderer* apRenderer)
    {
      // load texture from file
      SDL_Texture* texture = IMG_LoadTexture(apRenderer, arFilePath.c_str());
      if(!texture)
      {
        utils::log::Logger::error("SDL2 Error: Failed to load texture.\nSDL Error: " + std::string(SDL_GetError()) + "\n");
        return false;
      }

      // save texture in unordered map
      mTextureCache[arTextureId] = texture;
      return true;
    }

    SDL_Texture* TextureManager::getTexture(const std::string& arTextureId) const
    {
      // search for texture in cache and return it
      auto it = mTextureCache.find(arTextureId);
      if(it != mTextureCache.end())
      {
        return it->second;
      }
      utils::log::Logger::warning("Texture not found with ID: " + arTextureId);
      return nullptr;
    }

    bool TextureManager::releaseTexture(const std::string& arTextureId)
    {
      // search for texture in cache and release it
      auto it = mTextureCache.find(arTextureId);
      if(it != mTextureCache.end())
      {
        SDL_DestroyTexture(it->second);
        mTextureCache.erase(it);
        return true;
      }
      utils::log::Logger::warning("Texture with ID '" + arTextureId + "' not found.");
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