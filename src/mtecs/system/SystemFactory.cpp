#include "mtecs/system/SystemFactory.hpp"

namespace mtecs::internal
{
    SystemFactory::SystemFactory(Behaviour* behaviour) :
	behaviour(behaviour)
    {

    }
    
    System* SystemFactory::create(uint systemUid, uint id)
    {
	System* system = utility::Factory<System, uint, uint>::create(systemUid, id);
	BaseSystem* baseSystem = (BaseSystem*)system;

	baseSystem->setBehaviour(*behaviour);

	return system;
    }
}

