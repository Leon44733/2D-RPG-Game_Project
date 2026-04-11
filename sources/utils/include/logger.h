/**
 * ###############################################################################
 *  File: logger.h
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 31.January 2025, 8:47:34 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 11.April 2026, 5:13:35 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <thread>
#include <mutex>
#include <queue>
#include <fstream>
#include <condition_variable>

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
       * @brief Constructor for Logger class.
       * Initializes logger and starts worker thread.
       */
      Logger();

      /**
       * @brief Destructor for Logger class.
       * Shuts down logger and joins worker thread.
       */
      ~Logger();

      /**
       * @brief Process the log message queue.
       */
      void processQueue();

      /**
       * @brief Log message with info severity level.
       * @param arMsg message to log
       */
      void info(const std::string& arMsg);

      /**
       * @brief Log message with warning severity level.
       * @param arMsg message to log
       */
      void warning(const std::string& arMsg);

      /**
       * @brief Log message with error severity level.
       * @param arMsg message to log
       */
      void error(const std::string& arMsg);

    private:
      Logger(const Logger&) = delete;            // prevent copy-construction
      Logger& operator=(const Logger&) = delete; // prevent assignment

      /**
       * @brief Enum class for different severity levels.
       */
      enum class LogLevel
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
      void log(LogLevel aLevel, const std::string& arMsg);

      std::thread             mWorker;  // worker thread for processing log messages
      std::mutex              mMtx;     // mutex for synchronizing access to the log queue
      std::queue<std::string> mQueue;   // queue for storing log messages
      std::condition_variable mCv;      // condition variable for signaling the worker thread
      bool                    mRunning; // flag to indicate if logger is running
      std::ofstream           mLogfile; // file stream for logging to a file
    };
  }
}

#endif // LOGGER_H