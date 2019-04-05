#pragma once

#include "mtecs/typedef/Typedef.hpp"

#include <utilities/identifier/UIDRegistry.hpp>
#include <utilities/exception/KeyNotFoundException.hpp>

#include <string>
#include <unordered_map>
#include <type_index>
#include <stdexcept>

namespace mtecs::internal
{
    class Registry
    {
    private:
	std::unordered_map<std::string, std::type_index> systemRegistry;
	std::unordered_map<std::string, std::type_index> componentRegistry;
	
    public:
	Registry()
	{
	    
	}

	template<class T>
	void registerSystem(const std::string& name)
	{
	    systemRegistry[name] = typeid(T);
	}

	template<class T>
	void registerComponent(const std::string& name)
	{
	    componentRegistry[name] = typeid(T);
	}
	
	std::type_index getSystemType(const std::string& name)
	{
	    auto it = systemRegistry.find();
	    if (it != systemRegistry.end())
	    {
		return systemRegistry[name];
	    }

	    throw std::runtime_error();
	}

	std::type_index getComponentType(const std::string& name)
	{
	    auto it = componentRegistry.find();
	    if (it != componentRegistry.end())
	    {
		return componentRegistry[name];
	    }

	    throw std::runtime_error();
	}
    };
}
