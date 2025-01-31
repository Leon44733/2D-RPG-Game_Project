/**
 * ###############################################################################
 *  File: logger.h
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 31.January 2025, 8:47:34 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 31.January 2025, 9:20:06 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>

namespace Utils
{
    namespace LOG
    {
        /**
         * @brief Logger class for logging messages with different severity levels.
         */
        class Logger
        {
            public:
                /**
                 * @brief Enum class for different severity levels.
                 */
                enum class Level
                {
                    INFO,       // Info level
                    WARNING,    // Warning level 
                    ERROR       // Error level
                };

                /**
                 * @brief Log message with severity level.
                 * 
                 * @param aLevel severity level
                 * @param aMessage message to log
                 */
                static void log(Level, const std::string&);

                /**
                 * @brief Log message with info severity level.
                 * 
                 * @param aMessage message to log
                 */
                static void info(const std::string&);

                /**
                 * @brief Log message with warning severity level.
                 * 
                 * @param aMessage message to log
                 */
                static void warning(const std::string&);

                /**
                 * @brief Log message with error severity level.
                 * 
                 * @param aMessage message to log
                 */
                static void error(const std::string&);
        };
    }
}

#endif // LOGGER_H