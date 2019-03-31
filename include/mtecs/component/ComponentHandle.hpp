#pragma once

#include "mtecs/typedef/Typedef.hpp"
#include "mtecs/component/Handle.hpp"

namespace mtecs
{
    template<class T>
    class ComponentHandle
    {
    private:
	internal::Handle& handle;
	
    public:
	ComponentHandle(internal::Handle& handle) :
	    handle(handle)
	{
	      
	}
            
	inline T* operator ->()
	{ 
	    return static_cast<T*>(handle.get());
	}

	inline T operator *()
	{ 
	    return *static_cast<T*>(handle.get());
	}

	inline bool operator ==(const ComponentHandle<T>& other)
	{
	    return handle == other.handle;
	}

	inline bool operator !=(const ComponentHandle<T>& other)
	{
	    return handle != other.handle;
	}
    };
}
