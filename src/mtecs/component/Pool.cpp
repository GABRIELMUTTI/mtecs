#include "mtecs/component/Pool.hpp"

namespace mtecs::internal
{
    bool Pool::isIndexValid(uint index) const
    {
	return index < capacity;
    }

    Pool::Pool(std::size_t objSize, uint allocationStep) :
	array(nullptr),
	objSize(sizeof(char) * objSize),
	capacity(0),
	count(0),
	allocationStep(allocationStep)
    {
	allocate(allocationStep);
    }

            
    void Pool::add()
    {
	count++;
    }

    void Pool::remove()
    {
	count--;
    }

    char* Pool::get(uint index) const
    {
	return &array[index];
    }

    void Pool::allocate(uint amount)
    {
	uint newCapacity = capacity + amount;
	char* newArray = new char[sizeof(char) * objSize];

	if (array != nullptr)
	{
	    for (uint i = 0; i < capacity; i++)
	    {
		newArray[i] = array[i];
	    }
	}

	delete[] array;
	array = newArray;
	capacity = newCapacity;
    }

    void Pool::deallocate(uint amount)
    {
	int newCapacity = capacity - amount;

	if (newCapacity > 0)
	{
	    char* newArray = new char[sizeof(char) * objSize];

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
	    char* tmp = new char[objSize];

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
