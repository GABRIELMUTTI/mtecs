#include "mtecs/system/SystemInjector.hpp"

namespace mtecs::internal
{
    SystemInjector::SystemInjector(Managers managers) :
	managers(managers)
    {
	
    }

    void SystemInjector::inject(System& system)
    {
	static_cast<BaseSystem&>(system).setManagers(managers);
    }
}


