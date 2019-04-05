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
	typedef utility::Factory<System, std::type_index, uint> SystemFactory;
	
    private:
	std::vector<System*> systems;
	std::vector<System*> newSystems;

	SystemFactory* systemFactory;

    public:
	SystemManager(SystemFactory* systemFactory);
	
	void initialize();
	void update(float deltaTime);

	System* getSystem(std::type_index systemUid) const;
	void addSystem(std::type_index systemUid);
	void removeSystem(std::type_index systemUid);
    };	
}



