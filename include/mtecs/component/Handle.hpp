#pragma once

#include "mtecs/typedef/Typedef.hpp"
#include "mtecs/component/Pool.hpp"

namespace mtecs::internal
{
    class Handle
    {
    private:
	const Pool& pool;
	uint index;
	
    public:
	Handle(const Pool& pool, uint index);
	
	inline void* get();

	inline bool operator ==(Handle& other) const
	{
	    return (index == other.index) && (pool == other.pool);
	}

	inline bool operator !=(Handle& other) const
	{
	    return (index != other.index) && (pool != other.pool);
	}
    };
}
