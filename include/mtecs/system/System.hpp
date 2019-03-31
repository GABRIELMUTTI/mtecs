#pragma once

#include "mtecs/typedef/Typedef.hpp"

namespace mtecs::internal
{   
    class System
    {
    private:
	uint id;
	bool enabled;
	
    public:
	System(uint id);
	
	virtual void update(float deltaTime) = 0;
	virtual void initialize() = 0;

	uint getId() const;
	bool isEnabled() const;

	void setEnabled(bool enabled);
    };	
}
