#pragma once

#include "mtecs/typedef/Typedef.hpp"
#include "mtecs/system/System.hpp"
#include "mtecs/api/Behaviour.hpp"
#include "mtecs/api/BaseSystem.hpp"

#include <utilities/factory/Factory.hpp>

namespace mtecs::internal
{
    class SystemFactory : public utility::Factory<System, uint, uint>
    {
    private:
	Behaviour* behaviour;

    public:
	SystemFactory(Behaviour* behaviour);

	System* create(uint systemUid, uint id);
    };
}
