#pragma once

#include "mtecs/typedef/Typedef.hpp"

#include <vector>
#include <cstring>

namespace mtecs::internal
{
    class Pool
    {
    private:
	char* array;
	std::size_t objSize;
	uint capacity;
	uint count;
	uint allocationStep;

	bool isIndexValid(uint index) const;
	
    public:
	Pool(std::size_t objSize, uint allocationStep);
	
	char* get(uint index) const;
	void add();
        void remove();
        void allocate(uint amount);
        void deallocate(uint amount);
        void swap(uint indexA, uint indexB);
            
        uint getCapacity() const;
        uint getCount() const;
    };	
}
