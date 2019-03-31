#include "mtecs/component/ComponentManager.hpp"

namespace mtecs::internal
{
    ComponentManager::ComponentManager(uint allocationStep) :
	allocationStep(allocationStep)
    {

    }

    void ComponentManager::createPool(std::size_t componentSize, uint index)
    {
	Pool* newPool = new Pool(componentSize, allocationStep);

	if (index >= componentPools.size())
	{
	    componentPools.resize(index + 1, nullptr);
	}
	    
	componentPools[index] = newPool;
    }
	
    void ComponentManager::allocateInPools()
    {
	for (Pool* pool : componentPools)
	{
	    pool->allocate(allocationStep);
	}
    }

    Handle ComponentManager::getComponent(uint entityId, const Mask& mask) const
    {
	unsigned int poolIndex = mask.index();
	return Handle(*componentPools[poolIndex], entityId);
    }

    Handle ComponentManager::addComponent(uint entityId, const Mask& mask)
    {
	uint index = mask.index();
	Pool* pool;

	// Fetch pool;
	if (index + 1 <= componentPools.size())
	{
	    pool = componentPools[index];
	}
	else // Create new pool.
	{
	    createPool<T>(index);
	    pool = componentPools[index];
	}

	if (pool == nullptr)
	{
	    createPool<T>(index);
	    pool = componentPools[index];
	}

	uint poolCapacity = pool->getCapacity();
	if (entityId >= poolCapacity)
	{
	    pool->allocate((entityId - poolCapacity) + allocationStep);    
	}

	pool->add(entityId);

	return Handle(componentPools[index], entityId);
    }

    void ComponentManager::removeComponent(uint entityId, const Mask& mask)
    {
	uint index = mask.index();
	componentPools[index]->remove(entityId);
    }
}
