#include "mtecs/group/Group.hpp"

namespace mtecs
{
    Group::Group(const Mask& mask, const internal::ComponentManager& componentManager) :
	mask(mask),
	componentManager(componentManager)
    {

    }

    Entity* Group::get(uint index) const
    {
	return entities[index];
    }

    void Group::add(Entity* entity)
    {
	entities.push_back(entity);
    }

    void Group::remove(Entity* entity)
    {
	entities.erase(std::remove(entities.begin(), entities.end(), entity), entities.end());
    }

    bool Group::entityBelongsToGroup(const Entity& entity) const
    {
	return entity.hasComponents(mask);
    }

    bool Group::hasComponents(const Mask& componentMask, Mask::Has has) const
    {
	return mask.has(componentMask, has);
    }

    Mask Group::getMask() const
    {
	return mask;
    }

    const std::vector<Entity*>& Group::getEntities1() const
    {
	return entities;
    }
}
