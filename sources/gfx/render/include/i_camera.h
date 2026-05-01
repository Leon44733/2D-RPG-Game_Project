/**
 * ###############################################################################
 *  File: i_camera.h
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 07.March 2025, 10:36:50 am
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 01.May 2026, 6:55:26 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef I_CAMERA_H
#define I_CAMERA_H

#include <SDL3/SDL.h>

namespace gfx
{
  namespace render
  {
    /**
     * @brief ICamera interface class.
     */
    class ICamera
    {
    public:
      /**
       * @brief Virtual ICamera destructor.
       */
      virtual ~ICamera() = default;

      /**
       * @brief Virtual function to update camera position.
       * @param aNewPosX new x position
       * @param aNewPosY new y position
       */
      virtual void update(int aNewPosX, int aNewPosY) = 0;

      /**
       * @brief Virtual function to get camera position.
       * @return camera position
       */
      virtual SDL_Point getPos() const = 0;
    };
  }
}

#endif // I_CAMERA_H