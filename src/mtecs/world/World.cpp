#include "mtecs/world/World.hpp"

namespace mtecs
{
    World::World(const std::string& name, Behaviour* behaviour) :
	behaviour(behaviour),
	name(name),
	componentManager(internal::ComponentManager(100)),
	groupManager(internal::GroupManager(entityManager, componentManager, componentRegistry)),
	systemManager(internal::SystemManager(new internal::SystemFactory(behaviour)))
    {
	behaviour->setManagers(getManagers());
    }
    
    void World::update(float deltaTime)
    {
	systemManager.update(deltaTime);
    }

    Behaviour* World::getBehaviour()
    {
	return behaviour;
    }

    Managers World::getManagers()
    {
	Managers managers;
	managers.entityManager = &entityManager;
	managers.componentManager = &componentManager;
	managers.componentRegistry = &componentRegistry;
	managers.systemManager = &systemManager;
	managers.groupManager = &groupManager;

	return managers;
    }
}
