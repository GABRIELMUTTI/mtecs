#pragma once

#include "mtecs/typedef/Typedef.hpp"
#include "mtecs/entity/EntityManager.hpp"
#include "mtecs/component/ComponentManager.hpp"
#include "mtecs/component/ComponentRegistry.hpp"
#include "mtecs/system/SystemManager.hpp"
#include "mtecs/group/GroupManager.hpp"

namespace mtecs
{
    typedef struct managers_s
    {
	internal::EntityManager* entityManager;
	internal::ComponentManager* componentManager;
	internal::ComponentRegistry* componentRegistry;
	internal::SystemManager* systemManager;
	internal::GroupManager* groupManager;
    } Managers;

    class Behaviour
    {
    private:
	Managers managers;
	
    public:
	Behaviour();

	void setManagers(Managers managers)
	{
	    this->managers = managers;
	}
	
	// EntityManager functions:
	inline Entity* createEntity(const std::string& name)
	{
	    return managers.entityManager->createEntity(name);
	}

	inline void destroyEntity(uint entityId)
	{
	    managers.entityManager->destroyEntity(entityId);
	}

	inline Entity* getEntity(uint entityId)
	{
	    return managers.entityManager->getEntity(entityId);
	}

	// ComponentManager functions:
	template<class T> inline ComponentHandle<T> getComponent(Entity* entity)
	{
	    return ComponentHandle<T>(managers.componentManager->getComponent(entity->getId(), managers.componentRegistry->getMask<T>()));
	}

	template<class T> inline ComponentHandle<T> addComponent(Entity* entity)
	{
	    return ComponentHandle<T>(managers.componentManager->addComponent(entity->getId(), managers.componentRegistry->getMask<T>(), sizeof(T)));
	}

	template<class T> inline void removeComponent(Entity* entity)
	{
	    managers.componentManager->removeComponent(entity->getId(), managers.componentRegistry->getMask<T>());
	}
    };
}
