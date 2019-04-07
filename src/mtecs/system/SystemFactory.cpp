#include "mtecs/system/SystemFactory.hpp"

namespace mtecs::internal
{
    SystemFactory::SystemFactory(Managers managers) :
	managers(managers)
    {

    }
    
    System* SystemFactory::create(uint key, uint id)
    {
	System* system = utility::Factory<System, uint, uint>::create(key, id);
	system->setManagers(managers);

	return system;
    }
}

