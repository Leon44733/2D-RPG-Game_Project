/**
 * ###############################################################################
 *  File: i_camera.h
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 07.March 2025, 10:36:50 am
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 07.March 2025, 11:10:13 am
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef I_CAMERA_H
#define I_CAMERA_H

#include <SDL.h>

namespace gfx
{
  namespace render
  {
    class ICamera
    {
      public:
        virtual ~ICamera() = default;
        
        virtual void update(int aPlayerPosX, int aPlayerPosY) = 0;
        virtual SDL_Point getPos() const = 0;
    };
  }
}

#endif // I_CAMERA_H