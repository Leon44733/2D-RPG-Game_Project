/**
 * ###############################################################################
 *  File: logger.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 31.January 2025, 8:47:14 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Tu 14.April 2026, 7:37:30 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#include <filesystem>
#include <iostream>
#include <sstream>

#include "utils/include/logger.h"

namespace utils
{
  namespace log
  {
    Logger::Logger()
    {
      mRunning = true;
      
      std::filesystem::path log_dir = "logs";
      std::filesystem::path logfile_path = log_dir / "log.txt";

      if(!std::filesystem::exists(log_dir))
        std::filesystem::create_directories(log_dir);
      
      mLogfile.open(logfile_path, std::ios::app);
      if (!mLogfile.is_open())
      {
        std::cerr << "Logger: Failed to open log file!\n";
      }

      mWorker = std::thread(&Logger::processQueue, this);
    }

    Logger::~Logger()
    {
      mRunning = false;
      mCv.notify_all();

      if(mWorker.joinable())
        mWorker.join();

      if(mLogfile.is_open())
        mLogfile.close();
    }

    void Logger::processQueue()
    {
      while(true)
      {
        std::unique_lock<std::mutex> lock(mMtx);
        mCv.wait(lock, [&]() {return !mQueue.empty() || !mRunning;});

        if(!mRunning && mQueue.empty())
          break;

        std::queue<std::string> local_queue;
        std::swap(local_queue, mQueue);

        lock.unlock();

        while(!local_queue.empty())
        {
          std::cout << local_queue.front() << std::endl;
          mLogfile << local_queue.front() << std::endl;
          local_queue.pop();
        }
      }
    }

    void Logger::info(const std::string& arMsg)
    {
      log(LogLevel::INFO, arMsg);
    }

    void Logger::warning(const std::string& arMsg)
    {
      log(LogLevel::WARNING, arMsg);
    }

    void Logger::error(const std::string& arMsg)
    {
      log(LogLevel::ERROR, arMsg);
    }

    void Logger::log(LogLevel aLevel, const std::string& arMsg)
    {
      std::stringstream ss;
      
      auto now  = std::chrono::system_clock::now();
      auto time = std::chrono::system_clock::to_time_t(now);
      auto ms   = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;

      std::tm tm = *std::localtime(&time);
      ss << std::put_time(&tm, "[%Y-%m-%d %H:%M:%S") << '.' << std::setw(3) << std::setfill('0') << ms.count() << "]";

      switch(aLevel)
      {
      case LogLevel::INFO:    ss << " [INFO ] " << arMsg; break;
      case LogLevel::WARNING: ss << " [WARN ] " << arMsg; break;
      case LogLevel::ERROR:   ss << " [ERROR] " << arMsg; break;
      }

      {
        std::lock_guard<std::mutex> lock(mMtx);
        mQueue.push(ss.str());
      }
      mCv.notify_one();
    }
  }
}