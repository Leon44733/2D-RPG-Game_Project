/**
 * ###############################################################################
 *  File: texture_manager.h
 *  Project: 2D-RPG-Game
 *  Created Date: We 29.January 2025, 9:34:49 am
 *  Author: lbarwe
 *  -----
 *  Last Modified: Mo 17.February 2025, 4:01:08 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SDL2/SDL.h>
#include <string>
#include <unordered_map>

namespace GFX
{
  namespace Texture
  {
    class TextureManager
    {
        public:
          TextureManager();
          ~TextureManager();
          
          bool load(const std::string&, const std::string&, SDL_Renderer*);
          SDL_Texture* getTexture(const std::string&) const;
          
          void releaseTexture(const std::string&);
          void clearCache();

        private:
          std::unordered_map<std::string, SDL_Texture*> mTextureCache;
    };
  }
}

#endif // TEXTURE_MANAGER_H