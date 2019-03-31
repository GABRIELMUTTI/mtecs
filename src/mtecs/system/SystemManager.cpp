#include "mtecs/system/SystemManager.hpp"

namespace mtecs::internal
{
    SystemManager::SystemManager(SystemFactory* systemFactory) :
	systemFactory(systemFactory)
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

    void SystemManager::removeSystem(uint systemUid)
    {
	if (systemUid >= systems.size()) { return; }
	
	System* system = systems[systemUid];
	systems.erase(std::remove(systems.begin(), systems.end(), system), systems.end());
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
    }
    
    void SystemManager::addSystem(uint systemUid)
    {
	System* newSystem = systemFactory->create(systemUid, systems.size());

	systems.push_back(newSystem);
	newSystems.push_back(newSystem);
    }

    System* SystemManager::getSystem(uint systemUid) const
    {
	if (systemUid >= systems.size()) { return nullptr; }
	return systems[systemUid];	    
    }
    
}
