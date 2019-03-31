#pragma once

#include "mtecs/typedef/Typedef.hpp"
#include "mtecs/component/Mask.hpp"
#include "mtecs/component/Pool.hpp"
#include "mtecs/component/Handle.hpp"

#include <typeindex>
#include <vector>

namespace mtecs::internal
{
    class ComponentManager
    {
    private:
	std::vector<Pool*> componentPools;
	uint allocationStep;

    private:
	void createPool(std::size_t componentSize, uint index);
	void allocateInPools();

    public:
	ComponentManager(uint allocationStep);

	Handle getComponent(uint entityId, const Mask& mask) const;
	Handle addComponent(uint entityId, const Mask& mask);
	void removeComponent(uint entityId, const Mask& mask);
    };	

}
