#include "mtecs/world/World.hpp"

namespace mtecs
{
    World::World(const std::string& name) :
	name(name),
	systemInjector(internal::SystemInjector(getManagers())),
	entityManager(componentManager),
	componentManager(internal::ComponentManager(10000000)),
	systemManager(internal::SystemManager(systemInjector)),
	groupManager(internal::GroupManager(entityManager, componentManager))

    {

    }
    
    void World::update(float deltaTime)
    {
	groupManager.updateGroups();
	entityManager.clearNewEntities();
	systemManager.update(deltaTime);
    }

    internal::Managers World::getManagers()
    {
	internal::Managers managers = internal::Managers(&entityManager, &componentManager, &systemManager, &groupManager);

	return managers;
    }
}
