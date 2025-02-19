/**
 * ###############################################################################
 *  File: logger.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 31.January 2025, 8:47:14 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Tu 18.February 2025, 3:22:44 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include "utils/include/Logger.h"

namespace Utils
{
    namespace LOG
    {
        void Logger::log(Level aLevel, const std::string& aMessage)
        {
            switch(aLevel)
            {
                case Level::INFO:
                    std::cout << "[INFO] " << aMessage << std::endl;
                    break;
                case Level::WARNING:
                    std::cout << "[WARNING] " << aMessage << std::endl;
                    break;
                case Level::ERROR:
                    std::cerr << "[ERROR] " << aMessage << std::endl;
                    break;
            }
        }

        void Logger::info(const std::string& aMessage)
        {
            log(Level::INFO, aMessage);
        }

        void Logger::warning(const std::string& aMessage)
        {
            log(Level::WARNING, aMessage);
        }

        void Logger::error(const std::string& aMessage)
        {
            log(Level::ERROR, aMessage);
        }
    }
}