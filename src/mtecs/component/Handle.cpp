#include "mtecs/component/Handle.hpp"

namespace mtecs::internal
{
    Handle::Handle(IPool& pool, uint index) :
	pool(pool),
	index(index)
    {
	
    }
	
    void* Handle::get()
    {
	return pool.get(index);
    }
}

