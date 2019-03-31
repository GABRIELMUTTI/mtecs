#include "mtecs/api/mtecs.hpp"

namespace mtecs
{
    World* createWorld(const std::string& name)
    {
	return new World(name, new Behaviour());
    }

    World* createWorld(const std::string& name, Behaviour* behaviour)
    {
	return new World(name, behaviour);
    }
}
