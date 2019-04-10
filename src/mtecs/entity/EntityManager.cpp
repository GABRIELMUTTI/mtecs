#include "mtecs/entity/EntityManager.hpp"

namespace mtecs::internal
{
    EntityManager::EntityManager(ComponentManager& componentManager) :
	componentManager(componentManager),
	Entities(entities),
	NewEntities(newEntities),
	DeadEntities(deadEntities)
    {

    }

    Entity* EntityManager::createEntity(const std::string& name)
    {
	int entityId;

	if (freeFragmentedIndexes.empty())
	{
	    entityId = entities.size();
	}
	else
	{
	    entityId = freeFragmentedIndexes.back();
	    freeFragmentedIndexes.pop_back();
	}

	Entity* entity = new Entity(entityId, name, componentManager);
	
	entities.push_back(entity);
	newEntities.push_back(entity);
	    
	return entity;
    }

    void EntityManager::destroyEntity(uint entityId)
    {
	deadEntities.push_back(entities[entityId]);
	if (entityId + 1 == entities.size())
	{
	    entities.erase(entities.begin() + entityId);
	}
	else
	{
	    entities[entityId] = nullptr;
	    freeFragmentedIndexes.push_back(entityId);
	    std::sort(freeFragmentedIndexes.rbegin(), freeFragmentedIndexes.rend());
	}
    }

    Entity* EntityManager::getEntity(uint entityId)
    {
	return entities[entityId];
    }

    void EntityManager::clearNewEntities()
    {
	newEntities.clear();
    }

}
