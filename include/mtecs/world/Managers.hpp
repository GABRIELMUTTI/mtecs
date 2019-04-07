#pragma once

#include "mtecs/entity/EntityManager.hpp"
#include "mtecs/component/ComponentManager.hpp"
#include "mtecs/system/SystemManager.hpp"
#include "mtecs/group/GroupManager.hpp"

namespace mtecs::internal
{
    struct Managers
    {
	Managers(EntityManager* entityManager,
		 ComponentManager* componentManager,
		 SystemManager* systemManager,
		 GroupManager* groupManager) :
	    entityManager(entityManager),
	    componentManager(componentManager),
	    systemManager(systemManager),
	    groupManager(groupManager)
	{
	    
	}
	
	EntityManager* const entityManager;
	ComponentManager* const componentManager;
	SystemManager* const systemManager;
	GroupManager* const groupManager;
    };
}
