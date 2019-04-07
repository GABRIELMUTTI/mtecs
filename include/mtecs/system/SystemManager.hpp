#pragma once

#include "mtecs/typedef/Typedef.hpp"
#include "mtecs/system/System.hpp"

#include <utl/factory/Factory.hpp>
#include <utl/type/TypeInfo.hpp>

#include <vector>
#include <algorithm>

namespace mtecs::internal
{
    class SystemManager
    {
	typedef utility::Factory<System, uint, uint> SystemFactory;
	
    private:
	std::vector<System*> systems;
	std::vector<System*> newSystems;

	SystemFactory* systemFactory;

    public:
	SystemManager(SystemFactory* systemFactory);
	
	void initialize();
	void update(float deltaTime);

	template<class T>
	T* getSystem() const
	{
	    uint systemIndex = utl::TypeInfo::getDerivedClassId<T, System>();
	    return systems[systemIndex];
	}

	template<class T>
	void addSystem()
	{
	    uint systemKey = utl::TypeInfo::getDerivedClassId<T, System>();
	    System* system = systemFactory->create(systemKey, systems.size());

	    systems.push_back(system);
	    newSystems.push_back(system);
	}

	template<class T>
	void removeSystem(std::type_index systemUid)
	{
	    uint systemKey = utl::TypeInfo::getDerivedClassId<T, System>();
	
	    System* system = systems[systemUid];
	    systems.erase(std::remove(systems.begin(), systems.end(), system), systems.end());
	    newSystems.erase(std::remove(systems.begin(), systems.end(), system), systems.end());
	}
    };	
}

