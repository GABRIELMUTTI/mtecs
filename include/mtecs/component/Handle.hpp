#pragma once

#include "mtecs/typedef/Typedef.hpp"
#include "mtecs/component/IPool.hpp"

namespace mtecs::internal
{
    class Handle
    {
    private:
		IPool& pool;
		uint index;
		bool isValid;
	
    public:
		Handle(IPool& pool, uint index);
	
		inline void* get();
		
		bool valid();
		void invalidate();

		inline bool operator ==(Handle& other) const
		{
			return index == other.index;
		}

		inline bool operator !=(Handle& other) const
		{
			return index != other.index;
		}

		inline void operator=(const Handle& other)
		{
			pool = other.pool;
			index = other.index;
		}
    };
}
