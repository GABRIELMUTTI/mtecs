#pragma once

#include "mtecs/typedef/Typedef.hpp"
#include "mtecs/component/Mask.hpp"
#include "mtecs/component/Component.hpp"
#include "mtecs/component/ComponentHandle.hpp"

#include <utl/type/TypeInfo.hpp>
#include <utl/memory/ArrayPool.hpp>
#include <utl/memory/IPool.hpp>


#include <vector>

namespace mtecs::internal
{
    class ComponentManager
    {
    private:
	std::vector<utl::IPool<Component>*> componentPools;
	uint allocationStep;

    public:
	ComponentManager(uint allocationStep) :
	    allocationStep(allocationStep)
	{

	}

	template<class T>
	ComponentHandle<T> getComponent(uint entityId) const
	{
	    uint componentIndex = utl::TypeInfo::getDerivedClassId<T, Component>();
	    
	    using PoolType = utl::ArrayPool<Component, T>;
	    PoolType* pool = static_cast<PoolType*>(componentPools[componentIndex]);

	    return ComponentHandle<T>(pool, pool->getHandle(entityId));
	}

	template<class T>
	ComponentHandle<T> addComponent(uint entityId)
	{

	    
	    uint componentIndex = utl::TypeInfo::getDerivedClassId<T, Component>();

	    if (componentIndex >= componentPools.size())
	    {
		componentPools.resize(componentIndex + 1, nullptr);
		
	    }

	    using PoolType = utl::ArrayPool<Component, T>;
	    PoolType* pool = static_cast<PoolType*>(componentPools[componentIndex]);

	    if (pool == nullptr)
	    {
		pool = new PoolType(allocationStep);
		componentPools[componentIndex] = pool;
	    }

	    pool->add(entityId);


	    return ComponentHandle<T>(pool, pool->getHandle(entityId));
	}

	template<class T>
	void removeComponent(uint entityId)
	{
	    uint componentIndex = utl::TypeInfo::getDerivedClassId<T, Component>();
	    auto pool = componentPools[componentIndex];

	    pool->remove(entityId);
	}

	template<class TFirst, class TSecond, class ... TRest>
	Mask getMask() const
	{
	    Mask mask = getMask<TFirst>();
	    return mask | getMask<TSecond, TRest ...>();
	}
	
	template<class T>
	Mask getMask() const
	{
	    return Mask(utl::TypeInfo::getId<T>());
	}
    };	
}
