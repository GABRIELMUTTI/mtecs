#include "mtecs/world/World.hpp"

namespace mtecs
{
    World::World(Behaviour* behaviour) :
	behaviour(behaviour),
	componentManager(internal::ComponentManager(100)),
	groupManager(internal::GroupManager(entityManager, componentManager, componentRegistry)),
	systemSetter(internal::SystemSetter(behaviour)),
	behaviour(new ::Behaviour(entityManager, componentManager, componentRegistry, groupManager, systemManager, systemSetter))
    {
	
    }

    void World::update(float deltaTime)
    {
	systemManager.update(deltaTime);
    }

    internal::Behaviour* World::getBehaviour()
    {
	return behaviour;
    }
}

