/**
 * ###############################################################################
 *  File: logger.h
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 31.January 2025, 8:47:34 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Fr 06.February 2026, 9:54:58 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <string>

namespace utils
{
  namespace log
  {
    /**
     * @brief Logger class for logging messages with different severity levels.
     */
    class Logger
    {
    public:
      /**
       * @brief Log message with info severity level.
       * @param arMsg message to log
       */
      static void info(const std::string& arMsg);

      /**
       * @brief Log message with warning severity level.
       * @param arMsg message to log
       */
      static void warning(const std::string& arMsg);

      /**
       * @brief Log message with error severity level.
       * @param arMsg message to log
       */
      static void error(const std::string& arMsg);

    private:
      Logger() = delete;                         // prevent instantiation of logger
      Logger(const Logger&) = delete;            // prevent copy-construction
      Logger& operator=(const Logger&) = delete; // prevent assignment

      /**
       * @brief Enum class for different severity levels.
       */
      enum class Level
      {
        INFO,    // info level
        WARNING, // warning level
        ERROR    // error level
      };

      /**
       * @brief Log message with severity level.
       * @param aLevel severity level
       * @param arMsg message to log
       */
      static void log(Level aLevel, const std::string& arMsg);
    };
  }
}

#endif // LOGGER_H