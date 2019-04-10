#include "mtecs/group/GroupManager.hpp"

namespace mtecs::internal
{

    GroupManager::GroupManager(const EntityManager& entityManager, const ComponentManager& componentManager) :
	entityManager(entityManager),
	componentManager(componentManager)
    {

    }

    void GroupManager::updateGroups()
    {
	for (Group* group : groups)
	{
	    for (Entity* newEntity : entityManager.NewEntities)
	    {
		if (group->entityBelongsToGroup(*newEntity))
		{
		    group->add(newEntity);
		}
	    }

	    for (Entity* deadEntity : entityManager.DeadEntities)
	    {
		if (group->entityBelongsToGroup(*deadEntity))
		{
		    group->remove(deadEntity);
		}
	    }
	}
    }

    void GroupManager::createGroup(const Mask& mask)
    {
	Group* group = new Group(mask, componentManager);

	for (Entity* entity : entityManager.Entities)
	{
	    if (entity->hasComponents(mask))
	    {
		group->add(entity);
	    }
	}

	groups.push_back(group);
    }	
}
