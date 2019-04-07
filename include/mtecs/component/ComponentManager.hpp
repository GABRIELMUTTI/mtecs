#pragma once

#include "mtecs/typedef/Typedef.hpp"
#include "mtecs/component/Mask.hpp"

#include <utl/type/TypeInfo.hpp>
#include <utl/memory/ArrayPool.hpp>
#include <utl/memory/GenericHandle.hpp>

#include <vector>

namespace mtecs::internal
{
    class ComponentManager
    {
    private:
	std::vector<ArrayPool*> componentPools;
	uint allocationStep;

    public:
	ComponentManager(uint allocationStep) :
	    allocationStep(allocationStep)
	{
	    uint numDerivedClasses = utl::TypeInfo::getNumRegisteredClasses<Component>();
	    componentPools.resize(numDerivedClasses, new ArrayPool(allocationStep));
	}

	template<class T>
	GenericHandle<T> getComponent(uint entityId, const utl::Type& type) const
	{
	    uint componentIndex = utl::TypeInfo::getDerivedClassId<T, Component>();
	    ArrayPool* pool = componentPools[componentIndex];
	
	    return Handle(*pool, pool->get(entityId));
	}

	template<class T>
	GenericHandle<T> addComponent(uint entityId, const utl::Type& type)
	{
	    uint componentIndex = utl::TypeInfo::getDerivedClassId<T, Component>();
	    ArrayPool* pool = componentPools[componentIndex];

	    pool->add(entityId);

	    return GenericHandle<T>(*pool, pool->get(entityId), true);
	}

	template<class T>
	void removeComponent(uint entityId, const utl::Type& type)
	{
	    uint componentIndex = utl::TypeInfo::getDerivedClassId<T, Component>();
	    ArrayPool* pool = componentPools[componentIndex];

	    pool->remove(entityId);
	}

	template<class TFirst, class ... TRest>
	Mask getMask()
	{
	    Mask mask = getMask<TFirst>();
	    return mask | getMask<TRest ...>();
	}
	
	template<class T>
	Mask getMask()
	{
	    return Mask(TypeInfo::getTypeId<T>());
	}
    };	
}
