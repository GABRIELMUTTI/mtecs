#pragma once

#include "mtecs/world/World.hpp"
#include "mtecs/api/Behaviour.hpp"
#include "mtecs/system/SystemFactory.hpp"

namespace mtecs
{
    World* createWorld(const std::string& name);
}
