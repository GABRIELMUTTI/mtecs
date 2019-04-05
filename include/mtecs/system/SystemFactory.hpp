#pragma once

#include "mtecs/typedef/Typedef.hpp"
#include "mtecs/system/System.hpp"
#include "mtecs/api/Behaviour.hpp"
#include "mtecs/api/BaseSystem.hpp"

#include <utilities/factory/Factory.hpp>

#include <type_index>

namespace mtecs::internal
{
    class SystemFactory : public utility::Factory<System, std::type_index, uint>
    {
    private:
	Behaviour* behaviour;

    public:
	SystemFactory(Behaviour* behaviour);

	System* create(std::type_index systemType, uint id);
    };
}
