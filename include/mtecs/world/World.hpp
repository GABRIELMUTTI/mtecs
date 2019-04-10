#pragma once

#include "mtecs/typedef/Typedef.hpp"
#include "mtecs/entity/EntityManager.hpp"
#include "mtecs/entity/Entity.hpp"
#include "mtecs/component/ComponentManager.hpp"
#include "mtecs/system/SystemManager.hpp"
#include "mtecs/group/GroupManager.hpp"
#include "mtecs/system/System.hpp"
#include "mtecs/system/SystemFactory.hpp"
#include "mtecs/world/Managers.hpp"
#include "mtecs/system/SystemInjector.hpp"

#include <string>

namespace mtecs
{
    class World
    {
    private:
	std::string name;

	internal::SystemInjector systemInjector;

	internal::EntityManager entityManager;
	internal::ComponentManager componentManager;
	internal::SystemManager systemManager;
	internal::GroupManager groupManager;

    public:
	World(const std::string& name);

	void update(float deltaTime);

	internal::Managers getManagers();

	template<class T>
	inline T* addSystem()
	{
	    return systemManager.addSystem<T>();
	}

	template<class T>
	inline void removeSystem()
	{
	    systemManager.removeSystem<T>();
	}

	template<class T>
	inline T* getSystem()
	{
	    return systemManager.getSystem<T>();
	}

	inline Entity& getEntity(uint id)
	{
	    return *entityManager.getEntity(id);
	}

	inline Entity& createEntity(const std::string& name)
	{
	    return *entityManager.createEntity(name);
	}
	
	inline void destroyEntity(Entity& entity)
	{
	    entityManager.destroyEntity(entity.getId());
	}

	template<class ... TComponents>
	inline Group getGroup()
	{
	    return groupManager.getGroup<TComponents ...>();
	}
    };
}
