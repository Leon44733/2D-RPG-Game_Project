/**
 * ###############################################################################
 *  File: sdl_context.h
 *  Project: 2D-RPG-Game
 *  Created Date: Sa 02.May 2026, 3:38:15 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 02.May 2026, 4:22:06 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2026 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef SDL_CONTEXT_H
#define SDL_CONTEXT_H

namespace utils::log
{
  //Forward declaration
  class Logger;
}

namespace platform
{
  /**
   * @brief SDLContext class for handling the SDL context.
   */
  class SDLContext
  {
  public:
    /**
     * @brief Constructor for SDLContext class.
     * @param arLogger reference to the logger instance for logging SDL-related messages
     */
    SDLContext(utils::log::Logger& arLogger);

    /**
     * @brief Destructor for SDLContext class.
     * Quits the SDL3 library.
     */
    ~SDLContext();
    
    /**
     * @brief Initializes the SDL3 library.
     * @return true if initialization is successful, false otherwise
     */
    bool init();

  private:
    SDLContext() = delete;                             // prevent default construction
    SDLContext(const SDLContext&) = delete;            // prevent copy-construction
    SDLContext& operator=(const SDLContext&) = delete; // prevent assignment

    utils::log::Logger& mrLogger; // reference to the logger instance
  };
}

#endif // SDL_CONTEXT_H