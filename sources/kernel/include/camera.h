/**
 * ###############################################################################
 *  File: camera.h
 *  Project: 2D-RPG-Game
 *  Created Date: We 05.March 2025, 11:36:11 am
 *  Author: lbarwe
 *  -----
 *  Last Modified: We 15.October 2025, 9:50:18 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef CAMERA_H
#define CAMERA_H

#include <SDL.h>

#include "gfx/render/include/i_camera.h"

namespace kernel
{
  /**
   * @brief Camera class for displaying player movement.
   * Inherits from ICamera.
   */
  class Camera : public gfx::render::ICamera
  {
  public:
    /**
     * @brief Construct new Camera object.
     */
    Camera();

    /**
     * @brief Construct new Camera object.
     * @param aWidth camera width based on window size
     * @param aHeight camera height based on window size
     * @param aWorldWidth world width based on background
     * @param aWorldHeight world height based on background
     */
    Camera(int aWidth, int aHeight, int aWorldWidth, int aWorldHeight);

    /**
     * @brief Update camera and move to position.
     * @param aMovePosX new x position
     * @param aMovePosY new y position
     */
    void update(int aMovePosX, int aMovePosY);

    /**
     * @brief Get current camera position.
     * @return camera position
     */
    SDL_Point getPos() const;

  private:
    int mWidth;       // camera width based on window size
    int mHeight;      // camera height based on window size
    int mWorldWidth;  // world width based on background
    int mWorldHeight; // world height based on background
    SDL_Point mPos;   // camera position
  };
}

#endif // CAMERA_H