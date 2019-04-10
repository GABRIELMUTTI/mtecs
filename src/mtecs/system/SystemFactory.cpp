#include "mtecs/system/SystemFactory.hpp"

namespace mtecs::internal
{
    SystemFactory::SystemFactory(Managers managers) :
	managers(managers)
    {

    }
    
    System* SystemFactory::create(uint key, uint id)
    {
	System* system = utl::Factory<System, uint, uint>::create(key, id);

	BaseSystem* baseSystem = static_cast<BaseSystem*>(system);
	baseSystem->setManagers(managers);

	return system;
    }
}

