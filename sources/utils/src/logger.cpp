/**
 * ###############################################################################
 *  File: logger.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 31.January 2025, 8:47:14 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: We 15.October 2025, 9:55:10 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include <iostream>

#include "utils/include/Logger.h"

namespace utils
{
  namespace log
  {
    void Logger::log(Level aLevel, const std::string& aMsg)
    {
      switch(aLevel)
      {
      case Level::INFO:
        std::cout << "[INFO] " << aMsg << std::endl;
        break;
      case Level::WARNING:
        std::cout << "[WARNING] " << aMsg << std::endl;
        break;
      case Level::ERROR:
        std::cerr << "[ERROR] " << aMsg << std::endl;
        break;
      }
    }

    void Logger::info(const std::string& aMsg)
    {
      log(Level::INFO, aMsg);
    }

    void Logger::warning(const std::string& aMsg)
    {
      log(Level::WARNING, aMsg);
    }

    void Logger::error(const std::string& aMsg)
    {
      log(Level::ERROR, aMsg);
    }
  }
}