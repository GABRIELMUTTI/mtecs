#include "mtecs/component/Pool.hpp"

namespace mtecs::internal
{
    bool Pool::isIndexValid(uint index) const
    {
	return index < capacity;
    }

    Pool::Pool(std::size_t objSize, uint allocationStep) :
	array(nullptr),
	objSize(sizeof(std::uint8_t) * objSize),
	capacity(0),
	count(0),
	allocationStep(allocationStep)
    {
	allocate(allocationStep);
    }

            
    void Pool::add(uint index)
    {
	count++;
    }

    void Pool::remove(uint index)
    {
	count--;
	handles[index].invalidate()
    }

    void* Pool::get(uint index) const
    {
	return (void*)(&array[index]);
    }

    void Pool::allocate(uint amount)
    {
	uint newCapacity = capacity + amount;
	std::uint8_t* newArray = new std::uint8_t[sizeof(std::uint8_t) * objSize];
	handles.resize(newCapacity, Handle(*this, -1));
	
	if (array != nullptr)
	{
	    for (uint i = 0; i < capacity; i++)
	    {
		newArray[i] = array[i];
		handles[i] = Handle(*this, i);
	    }
	}

	delete[] array;
	array = newArray;
	capacity = newCapacity;
    }

    void Pool::deallocate(uint amount)
    {
	int newCapacity = capacity - amount;
	handles.resize(newCapacity, Handle(*this, -1));
	
	if (newCapacity > 0)
	{
	    std::uint8_t* newArray = new std::uint8_t[sizeof(std::uint8_t) * objSize];

	    if (array != nullptr)
	    {
		for (int i = 0; i < newCapacity; i++)
		{
		    newArray[i] = array[i];
		}
	    }
                    
	    delete[] array;
	    array = newArray;
	}
	else
	{
	    capacity = 0;
	    delete[] array;
	    array = nullptr;
	}
    }

    void Pool::swap(uint indexA, uint indexB)
    {
	if (isIndexValid(indexA) && isIndexValid(indexB))
	{
	    std::uint8_t* tmp = new std::uint8_t[objSize];

	    memcpy(tmp, &array[indexB], objSize);
	    memcpy(&array[indexB], &array[indexA], objSize);
	    memcpy(&array[indexA], tmp, objSize);
	}
    }

    uint Pool::getCount() const
    {
	return count;
    }

    uint Pool::getCapacity() const
    {
	return capacity;
    }
}
