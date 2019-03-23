#pragma once

#include "mtecs/system/ISystem.hpp"
#include "mtecs/api/ISetter.hpp"
#include "mtecs/api/Behaviour.hpp"
#include "mtecs/api/System.hpp"

namespace mtecs
{
    namespace internal
    {
	class SystemSetter : public internal::ISetter<internal::ISystem>
	{
	private:
	    Behaviour* behaviour;
	
	public:
	    SystemSetter(Behaviour* behaviour) :
		behaviour(behaviour)
	    {
	    
	    }

	    void set(internal::ISystem& system)
	    {
		System& derivedSystem = static_cast<System&>(system);
		derivedSystem.setBehaviour(*behaviour);
	    }
	};	
    }
}
