/**
 * ###############################################################################
 *  File: camera.h
 *  Project: 2D-RPG-Game
 *  Created Date: We 05.March 2025, 11:36:11 am
 *  Author: lbarwe
 *  -----
 *  Last Modified: We 05.March 2025, 2:22:53 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef CAMERA_H
#define CAMERA_H

#include <SDL.h>

namespace kernel
{
  class Camera
  {
    public:
      Camera(int aWidth, int aHeight, int aWorldWidth, int aWorldHeight);
      void update(int aPlayerPosX, int aPlayerPosY);

      int getXPos() const;
      int getYPos() const;

  private:
      int mWidth;
      int mHeight;
      int mWorldWidth;
      int mWorldHeight;
      SDL_Point mPos;
  };
}

#endif // CAMERA_H