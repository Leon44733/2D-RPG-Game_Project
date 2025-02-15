/**
 * ###############################################################################
 *  File: texture_manager.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Tu 04.February 2025, 10:40:37 am
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 15.February 2025, 1:30:26 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include "src/ui/include/texture_manager.h"
#include "src/utils/include/logger.h"

namespace UI
{
  namespace GUI
  {
      TextureManager::TextureManager() {}

      TextureManager::~TextureManager()
      {
          for(auto& texture : mTextureCache)
          {
              SDL_DestroyTexture(texture.second);
          }
          clearCache();
      }

    bool TextureManager::load(const std::string& aFilePath, const std::string& aTextureId, SDL_Renderer* aRenderer)
    {
      // load bild file as surface
      SDL_Surface* tempSurface = SDL_LoadBMP(aFilePath.c_str());
      if(!tempSurface)
      {
        Utils::LOG::Logger::error("SDL2 Error: Failed to load image.\nSDL Error: " + std::string (SDL_GetError()) + "\n");
        return false;
      }

      // create texture from surface
      SDL_Texture* texture = SDL_CreateTextureFromSurface(aRenderer, tempSurface);
      SDL_FreeSurface(tempSurface);
      if (!texture)
      {
        Utils::LOG::Logger::error("SDL2 Error: Failed to create texture.\nSDL Error: " + std::string (SDL_GetError()) + "\n");
        return false;
      }

      // save texture in unordered map
      mTextureCache[aTextureId] = texture;
      return true;
    }

    SDL_Texture* TextureManager::getTexture(const std::string& aTextureId) const
    {
      auto it = mTextureCache.find(aTextureId);
      if(it != mTextureCache.end())
      {
          return it->second;
      }
      return nullptr;
    }

    void TextureManager::releaseTexture(const std::string& aTextureId)
    {
      mTextureCache.erase(aTextureId);
    }

    void TextureManager::clearCache()
    {
      mTextureCache.clear();
    }
  }
}