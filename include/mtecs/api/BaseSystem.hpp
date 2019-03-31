#pragma once

#include "mtecs/system/System.hpp"
#include "mtecs/api/Behaviour.hpp"

namespace mtecs
{
    class BaseSystem : public internal::System
    {
    private:
	Behaviour* behaviour;

    public:
	BaseSystem(uint id);

	void setBehaviour(Behaviour& behaviour);
    };
}
