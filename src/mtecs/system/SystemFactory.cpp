#include "mtecs/system/SystemFactory.hpp"

namespace mtecs::internal
{
    SystemFactory::SystemFactory(Behaviour* behaviour) :
	behaviour(behaviour)
    {

    }
    
    System* SystemFactory::create(std::type_index systemType, uint id)
    {
	System* system = utility::Factory<System, std::type_index, uint>::create(systemType, id);
	BaseSystem* baseSystem = (BaseSystem*)system;

	baseSystem->setBehaviour(*behaviour);

	return system;
    }
}

