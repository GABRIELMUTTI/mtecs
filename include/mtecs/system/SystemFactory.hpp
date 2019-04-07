#pragma once

#include "mtecs/typedef/Typedef.hpp"
#include "mtecs/system/System.hpp"
#include "mtecs/world/Managers.hpp"


#include <utl/factory/Factory.hpp>

namespace mtecs::internal
{
    class SystemFactory : public utility::Factory<System, uint, uint>
    {
    private:
	Managers managers;

    public:
	SystemFactory(Managers managers);

	System* create(uint key, uint id);
    };
}
