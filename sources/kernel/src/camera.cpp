/**
 * ###############################################################################
 *  File: camera.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: We 05.March 2025, 11:36:22 am
 *  Author: lbarwe
 *  -----
 *  Last Modified: We 05.March 2025, 2:22:53 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include "kernel/include/camera.h"

namespace kernel
{
  Camera::Camera(int aWidth, int aHeight, int aWorldWidth, int aWorldHeight) :
    mWidth(aWidth),
    mHeight(aHeight),
    mWorldWidth(aWorldWidth),
    mWorldHeight(aWorldHeight)
  {
    mPos.x = 0;
    mPos.y = 0;
  }

  void Camera::update(int aPlayerPosX, int aPlayerPosY)
  {
    mPos.x = aPlayerPosX - mWidth / 2;
    mPos.y = aPlayerPosY - mHeight / 2;

    // set camera limitation
    if (mPos.x < 0) {mPos.x = 0;}
    if (mPos.y < 0) {mPos.y = 0;}
    if (mPos.x > mWorldWidth - mWidth) {mPos.x = mWorldWidth - mWidth;}
    if (mPos.y > mWorldHeight - mHeight) {mPos.y = mWorldHeight - mHeight;}
  }

  int Camera::getXPos() const
  {
    return mPos.x;
  }

  int Camera::getYPos() const
  {
    return mPos.y;
  }
}