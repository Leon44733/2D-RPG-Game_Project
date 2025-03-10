/**
 * ###############################################################################
 *  File: camera.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: We 05.March 2025, 11:36:22 am
 *  Author: lbarwe
 *  -----
 *  Last Modified: Mo 10.March 2025, 1:38:30 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include <algorithm>

#include "kernel/include/camera.h"

namespace kernel
{
  Camera::Camera() {}
  Camera::Camera(int aWidth, int aHeight, int aWorldWidth, int aWorldHeight) :
    mWidth(aWidth),
    mHeight(aHeight),
    mWorldWidth(aWorldWidth),
    mWorldHeight(aWorldHeight)
  {
    mPos.x = 0;
    mPos.y = 0;
  }

  void Camera::update(int aMovePosX, int aMovePosY)
  {
    mPos.x += aMovePosX;
    mPos.y += aMovePosY;

    mPos.x = std::clamp(mPos.x, 0, mWorldWidth - mWidth);
    mPos.y = std::clamp(mPos.y, 0, mWorldHeight - mHeight);
  }

  SDL_Point Camera::getPos() const
  {
    return mPos;
  }
}