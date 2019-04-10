#pragma once

#include "mtecs/typedef/Typedef.hpp"
#include "mtecs/entity/Entity.hpp"
#include "mtecs/component/ComponentManager.hpp"

#include <utl/property/StructureProperty.hpp>

#include <vector>
#include <string>
#include <algorithm>

namespace mtecs::internal
{
    class EntityManager
    {
    private:
	std::vector<Entity*> entities;
	std::vector<Entity*> newEntities;
	std::vector<Entity*> deadEntities;

	std::vector<uint> freeFragmentedIndexes;
	ComponentManager& componentManager;

    public:
	const utl::StructureProperty<std::vector<Entity*>> Entities;
	const utl::StructureProperty<std::vector<Entity*>> NewEntities;
	const utl::StructureProperty<std::vector<Entity*>> DeadEntities;
	    
	EntityManager(ComponentManager& componentManager);
            
	Entity* createEntity(const std::string& name);
	void destroyEntity(uint entityId);
	Entity* getEntity(uint entityId);

	void clearNewEntities();
    };		
}
