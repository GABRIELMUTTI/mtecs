#pragma once

#include "mtecs/typedef/Typedef.hpp"
#include "mtecs/system/System.hpp"

#include <utilities/factory/Factory.hpp>

#include <vector>
#include <algorithm>

namespace mtecs::internal
{
    class SystemManager
    {
	typedef utility::Factory<System, uint, uint> SystemFactory;
	
    private:
	std::vector<System*> systems;
	std::vector<System*> newSystems;

	SystemFactory* systemFactory;

    public:
	SystemManager(SystemFactory* systemFactory);
	
	void initialize();
	void update(float deltaTime);

	System* getSystem(uint systemUid) const;
	void addSystem(uint systemUid);
	void removeSystem(uint systemUid);
    };	
}
