#include "mtecs/system/SystemManager.hpp"

namespace mtecs::internal
{
    SystemManager::SystemManager(utl::Injector<System>& systemInjector) :
	systemInjector(systemInjector),
	customInjector(nullptr)
    {
	
    }
    
    void SystemManager::initialize()
    {
	for (System* newSystem : newSystems)
	{
	    newSystem->initialize();
	}

	newSystems.clear();
    }

    void SystemManager::update(float deltaTime)
    {
	for (System* newSystem : newSystems)
	{
	    newSystem->initialize();
	}

	for (System* system : systems)
	{
	    system->update(deltaTime);
	}

	newSystems.clear();
    }    
}
