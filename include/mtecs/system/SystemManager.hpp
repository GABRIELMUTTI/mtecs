#pragma once

#include "mtecs/typedef/Typedef.hpp"
#include "mtecs/system/System.hpp"

#include <utl/factory/Factory.hpp>
#include <utl/type/TypeInfo.hpp>
#include <utl/injection/Injector.hpp>

#include <vector>
#include <algorithm>

namespace mtecs::internal
{
    class SystemManager
    {
	using SystemFactory = utl::Factory<System, uint, uint>;
	
    private:
	std::vector<System*> systems;
	std::vector<System*> newSystems;

	utl::Injector<System>& systemInjector;
	utl::Injector<System>* customInjector;

    public:
	SystemManager(utl::Injector<System>& systemInjector);
	
	void initialize();
	void update(float deltaTime);

	template<class T>
	T* getSystem() const
	{
	    uint systemIndex = utl::TypeInfo::getDerivedClassId<T, System>();
	    return static_cast<T*>(systems[systemIndex]);
	}

	template<class T>
	T* addSystem()
	{
	    uint systemKey = utl::TypeInfo::getDerivedClassId<T, System>();
	    System* system = new T(systemKey);

	    systemInjector.inject(*system);

	    if (customInjector != nullptr)
	    {
		customInjector->inject(*system);
	    }

	    systems.push_back(system);
	    newSystems.push_back(system);

	    return static_cast<T*>(system);
	}

	template<class T>
	void removeSystem()
	{
	    uint systemKey = utl::TypeInfo::getDerivedClassId<T, System>();
	
	    System* system = systems[systemKey];
	    systems.erase(std::remove(systems.begin(), systems.end(), system), systems.end());
	    newSystems.erase(std::remove(systems.begin(), systems.end(), system), systems.end());
	}
    };	
}

