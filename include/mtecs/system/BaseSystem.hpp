#pragma once

#include "mtecs/system/System.hpp"
#include "mtecs/world/Managers.hpp"

namespace mtecs
{
    class BaseSystem : public internal::System
    {
    public:
	internal::EntityManager* entityManager;
	internal::ComponentManager* componentManager;
	internal::SystemManager* systemManager;
	internal::GroupManager* groupManager;

    public:
	BaseSystem(uint id);
	
	void setManagers(internal::Managers Managers);

	template<class T>
	inline T* addSystem()
	{
	    return systemManager->addSystem<T>();
	}

	template<class T>
	inline void removeSystem()
	{
	    systemManager->removeSystem<T>();
	}

	template<class T>
	inline T* getSystem()
	{
	    return systemManager->getSystem<T>();
	}

	inline Entity& getEntity(uint id)
	{
	    return *entityManager->getEntity(id);
	}

	inline Entity& createEntity(const std::string& name)
	{
	    return *entityManager->createEntity(name);
	}
	
	inline void destroyEntity(Entity& entity)
	{
	    entityManager->destroyEntity(entity.getId());
	}

	template<class ... TComponents>
	inline Group* getGroup()
	{
	    return groupManager->getGroup<TComponents ...>();
	}
    };
}
