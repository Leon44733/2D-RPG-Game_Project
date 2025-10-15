/**
 * ###############################################################################
 *  File: logger.h
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 31.January 2025, 8:47:34 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: We 15.October 2025, 9:56:51 pm
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
       * @param aMsg message to log
       */
      static void info(const std::string& aMsg);

      /**
       * @brief Log message with warning severity level.
       * @param aMsg message to log
       */
      static void warning(const std::string& aMsg);

      /**
       * @brief Log message with error severity level.
       * @param aMsg message to log
       */
      static void error(const std::string& aMsg);

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
       * @param aMsg message to log
       */
      static void log(Level aLevel, const std::string& aMsg);
    };
  }
}

#endif // LOGGER_H