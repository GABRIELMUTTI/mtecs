#pragma once

#include "mtecs/typedef/Typedef.hpp"
#include "mtecs/entity/EntityManager.hpp"
#include "mtecs/entity/Entity.hpp"
#include "mtecs/component/ComponentManager.hpp"
#include "mtecs/component/ComponentRegistry.hpp"
#include "mtecs/component/ComponentHandle.hpp"
#include "mtecs/system/SystemManager.hpp"
#include "mtecs/group/GroupManager.hpp"
#include "mtecs/system/ISystem.hpp"
#include "mtecs/api/Behaviour.hpp"
#include "mtecs/api/SystemSetter.hpp"

#include <string>

namespace mtecs
{
    class World
    {
    private:
	Behaviour* behaviour;

	internal::EntityManager entityManager;
	internal::ComponentManager componentManager;
	internal::ComponentRegistry componentRegistry;
	internal::GroupManager groupManager;
	internal::SystemManager systemManager;
	internal::SystemSetter systemSetter;
	
    public:
	World(Behaviour* behaviour);

	void update(float deltaTime);

	Behaviour* getBehaviour();

	// Entity API:
	inline Entity* createEntity(const std::string& name)
	{
	    return behaviour->createEntity(name);
	}
	
	inline Entity* getEntity(uint entityId)
	{
	    return behaviour->getEntity(entityId);
	}
	
	inline void destroyEntity(Entity* entity)
	{
	    behaviour->destroyEntity(entity);
	}
	
	// Component API:
	template<class T>
	inline ComponentHandle<T> addComponent(Entity* entity)
	{
	    return behaviour->addComponent<T>(entity);
	}

	template<class T>
	inline void removeComponent(Entity* entity)
	{
	    behaviour->removeComponent<T>(entity);
	}
	
	template<class T>
	inline ComponentHandle<T> getComponent(Entity* entity)
	{
	    return behaviour->getComponent<T>(entity);
	}

	// System API:
	template<class T>
	inline T* addSystem()
	{
	    return behaviour->addSystem<T>();
	}

	template<class T>
	inline T* getSystem(uint systemId)
	{
	    return behaviour->getSystem<T>();
	}

	inline void removeSystem(uint systemId)
	{
	    behaviour->removeSystem(systemId);
	}

	// Group API:
	template<class ... TComponents>
	inline Group* getGroup()
	{
	    return behaviour->getGroup<TComponents ...>();
	}
    };
}
