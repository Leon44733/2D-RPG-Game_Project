/**
 * ###############################################################################
 *  File: factory.h
 *  Project: 2D-RPG-Game
 *  Created Date: Mo 20.October 2025, 8:23:50 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Mo 20.October 2025, 9:17:21 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef FACTORY_H
#define FACTORY_H

#include "utils/include/logger.h"


//TDOO: überarbeiten!!!
namespace utils
{
  namespace factory
  {
    template <typename Base>
    class Factory
    {
    public:
      using CreatorFunc = std::function<std::unique_ptr<Base>()>;

      static std::unique_ptr<Base> create(const std::string& aObjName)
      {
        auto it = getRegistry().find(aObjName);
        if (it != getRegistry().end())
        {
          return (it->second)();
        }
        utils::log::Logger::error("Factory: Unknown type requested: " + aObjName);
        return nullptr;
      }
      
    private:
      static std::unordered_map<std::string, CreatorFunc>& getRegistry()
      {
        static std::unordered_map<std::string, CreatorFunc> registry;
        return registry;
      }
      
      static void registerType(const std::string& aObjName, CreatorFunc aCreator)
      {
        getRegistry()[aObjName] = aCreator;
      }
      
    };
  }
}

#endif // FACTORY_H