#pragma once

#include "mtecs/typedef/Typedef.hpp"
#include "mtecs/entity/EntityManager.hpp"
#include "mtecs/entity/Entity.hpp"
#include "mtecs/component/ComponentManager.hpp"
#include "mtecs/component/ComponentRegistry.hpp"
#include "mtecs/component/ComponentHandle.hpp"
#include "mtecs/system/SystemManager.hpp"
#include "mtecs/group/GroupManager.hpp"
#include "mtecs/system/System.hpp"
#include "mtecs/api/Behaviour.hpp"
#include "mtecs/system/SystemFactory.hpp"

#include <string>

namespace mtecs
{
    class World
    {
    private:
	Behaviour* behaviour;
	std::string name;

	internal::EntityManager entityManager;
	internal::ComponentManager componentManager;
	internal::ComponentRegistry componentRegistry;
	internal::GroupManager groupManager;
	internal::SystemManager systemManager;

    public:
	World(const std::string& name, Behaviour* behaviour);

	void update(float deltaTime);

	Behaviour* getBehaviour();
	Managers getManagers();
    };
}
