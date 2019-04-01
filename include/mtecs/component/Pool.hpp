#pragma once

#include "mtecs/typedef/Typedef.hpp"

#include "mtecs/component/IPool.hpp"
#include "mtecs/component/Handle.hpp"

#include <vector>
#include <cstring>
#include <cstdint>

namespace mtecs::internal
{
    class Pool : public IPool
    {
    private: 
	std::uint8_t* array;
	std::size_t objSize;
	uint capacity;
	uint count;
	uint allocationStep;
	std::vector<Handle> handles;
	
	bool isIndexValid(uint index) const;
	
    public:
	Pool(std::size_t objSize, uint allocationStep);

	void* get(uint index) const;

	void add(uint index);
        void remove(uint index);
        void allocate(uint amount);
        void deallocate(uint amount);
        void swap(uint indexA, uint indexB);
            
        uint getCapacity() const;
        uint getCount() const;
    };	
}
