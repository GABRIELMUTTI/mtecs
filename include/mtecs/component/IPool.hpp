#pragma once

#include "mtecs/typedef/Typedef.hpp"

namespace mtecs::internal
{
    class IPool
    {
    public:
	virtual void* get(uint index) const = 0;

	virtual void add(uint index) = 0;
        virtual void remove(uint index) = 0;
        virtual void allocate(uint amount) = 0;
        virtual void deallocate(uint amount) = 0;
        virtual void swap(uint indexA, uint indexB) = 0;
            
        virtual uint getCapacity() const = 0;
        virtual uint getCount() const = 0;
    };
}
