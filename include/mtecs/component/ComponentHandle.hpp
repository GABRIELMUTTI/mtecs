#pragma once

#include "mtecs/component/Component.hpp"

#include <utl/memory/ArrayPool.hpp>
#include <utl/memory/GenericHandle.hpp>

namespace mtecs
{
    template<class T>
    class ComponentHandle : public utl::GenericHandle<utl::ArrayPool<Component, T>, Component, T>
    {
	using PoolType = utl::ArrayPool<Component, T>;
	
    public:
	ComponentHandle() :
	    utl::GenericHandle<PoolType, Component, T>()
	{
	    
	}

	ComponentHandle(const PoolType* const pool, utl::Handle<Component> handle) :
	    utl::GenericHandle<PoolType, Component, T>(pool, handle)
	{
	    
	}

	ComponentHandle(const PoolType* const pool, uint index, bool validity) :
	    utl::GenericHandle<PoolType, Component, T>(pool, index, validity)
	{
	    
	}
    };
}
