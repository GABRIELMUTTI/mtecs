#include "mtecs/system/System.hpp"

namespace mtecs::internal
{
    System::System(uint id) :
	id(id),
	enabled(false)
    {
	    
    }
	
    uint System::getId() const
    {
	return id;
    }
	
    bool System::isEnabled() const
    {
	return enabled;
    }

    void System::setEnabled(bool enabled)
    {
	this->enabled = enabled;
    }
}
