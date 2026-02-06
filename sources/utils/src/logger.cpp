/**
 * ###############################################################################
 *  File: logger.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 31.January 2025, 8:47:14 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 15.November 2025, 3:43:36 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include <iostream>

#include "utils/include/logger.h"

namespace utils
{
  namespace log
  {
    void Logger::log(Level aLevel, const std::string& arMsg)
    {
      switch(aLevel)
      {
      case Level::INFO:
        std::cout << "[INFO] " << arMsg << std::endl;
        break;
      case Level::WARNING:
        std::cout << "[WARNING] " << arMsg << std::endl;
        break;
      case Level::ERROR:
        std::cerr << "[ERROR] " << arMsg << std::endl;
        break;
      }
    }

    void Logger::info(const std::string& arMsg)
    {
      log(Level::INFO, arMsg);
    }

    void Logger::warning(const std::string& arMsg)
    {
      log(Level::WARNING, arMsg);
    }

    void Logger::error(const std::string& arMsg)
    {
      log(Level::ERROR, arMsg);
    }
  }
}