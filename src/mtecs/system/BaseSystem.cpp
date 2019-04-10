#include "mtecs/system/BaseSystem.hpp"

namespace mtecs
{
    BaseSystem::BaseSystem(uint id) : System(id)
    {
	
    }
    
    void BaseSystem::setManagers(internal::Managers managers)
    {
	this->entityManager = managers.entityManager;
	this->componentManager = managers.componentManager;
	this->systemManager = managers.systemManager;
	this->groupManager = managers.groupManager;
    }
}
