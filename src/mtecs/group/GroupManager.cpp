#include "mtecs/group/GroupManager.hpp"

namespace mtecs
{
    namespace internal
    {
	GroupManager::GroupManager(const EntityManager& entityManager,  ComponentManager& componentManager) :
	    entityManager(entityManager),
	    componentManager(componentManager)
	{

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
}
