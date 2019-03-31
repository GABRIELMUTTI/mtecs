#include "mtecs/api/BaseSystem.hpp"

namespace mtecs
{
    BaseSystem::BaseSystem(uint id) :
	internal::System(id)
    {
	
    }

    void BaseSystem::setBehaviour(Behaviour& behaviour)
    {
	this->behaviour = &behaviour;
    }
}
