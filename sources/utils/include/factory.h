/**
 * ###############################################################################
 *  File: factory.h
 *  Project: 2D-RPG-Game
 *  Created Date: Mo 20.October 2025, 8:23:50 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 11.April 2026, 4:15:45 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef FACTORY_H
#define FACTORY_H

#include "utils/include/logger.h"

namespace utils
{
  namespace factory
  {
    template <typename Base>
    class Factory
    {
    public:
      using CreatorFunc = std::function<std::unique_ptr<Base>()>;

      /**
       * @brief Create an instance of a registered type.
       * @param arObjName name of the type to create
       * @return pointer to the created instance
       */
      static std::unique_ptr<Base> create(const std::string& arObjName)
      {
        // find the creator function in the registry
        auto it = getRegistry().find(arObjName);
        if (it != getRegistry().end())
        {
          return (it->second)();
        }
        // TODO: utils::log::Logger::error("Factory: Unknown type requested: " + arObjName);
        return nullptr;
      }
      
      /**
       * @brief Register a type with the factory.
       * @param arObjName name of the type to register
       * @param aCreator creator function for the type
       */
      static void registerType(const std::string& arObjName, CreatorFunc aCreator)
      {
        getRegistry()[arObjName] = aCreator;
      }
      
    private:
      /**
       * @brief Get the registry map.
       * @return the reference to the registry map
       */
      static std::unordered_map<std::string, CreatorFunc>& getRegistry()
      {
        static std::unordered_map<std::string, CreatorFunc> registry;
        return registry;
      }
    };
  }
}

#endif // FACTORY_H