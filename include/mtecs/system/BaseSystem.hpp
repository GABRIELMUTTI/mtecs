#pragma once

#include "mtecs/system/System.hpp"
#include "mtecs/world/Managers.hpp"

namespace mtecs
{
    class BaseSystem : public System
    {
    private:
	Managers managers;

    public:
	void setManagers(Managers Managers);
    };
}
