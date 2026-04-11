/**
 * ###############################################################################
 *  File: logger.cpp
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 31.January 2025, 8:47:14 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 11.April 2026, 5:27:29 pm
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

      switch(aLevel)
      {
      case LogLevel::INFO:
        ss << "[INFO ] " << arMsg;
        break;
      case LogLevel::WARNING:
        ss << "[WARN ] " << arMsg;
        break;
      case LogLevel::ERROR:
        ss << "[ERROR] " << arMsg;
        break;
      }

      {
        std::lock_guard<std::mutex> lock(mMtx);
        mQueue.push(ss.str());
      }
      mCv.notify_one();
    }
  }
}