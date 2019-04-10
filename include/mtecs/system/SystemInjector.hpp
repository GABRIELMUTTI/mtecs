#pragma once

#include "mtecs/world/Managers.hpp"
#include "mtecs/system/BaseSystem.hpp"

#include <utl/injection/Injector.hpp>

namespace mtecs::internal
{
    class SystemInjector : public utl::Injector<System>
    {
    private:
	Managers managers;
	
    public:
	SystemInjector(Managers managers);

	void inject(System& system);
    };
}
