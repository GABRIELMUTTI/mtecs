#pragma once

#include "mtecs/entity/Entity.hpp"
#include "mtecs/group/GroupComponentIterator.hpp"
#include "mtecs/component/ComponentHandle.hpp"
#include "mtecs/component/ComponentManager.hpp"
#include "mtecs/component/ComponentRegistry.hpp"

#include <vector>
#include <tuple>

namespace mtecs
{
    template<class ... Components>
    class GroupComponentView
    {
        typedef std::vector<Entity*> Entities;
    
    private:
	const Entities& entities;
	std::tuple<ComponentHandle<Components>& ...> handles;
	const internal::ComponentManager& componentManager;
	
    public:
	GroupComponentView(const Entities& entities, ComponentHandle<Components>& ... handles, const internal::ComponentManager& componentManager) :
	    entities(entities),
	    handles(handles ...),
	    componentManager(componentManager)
	{

	}

	GroupComponentIterator<Entities, Components ...> begin()
	{
	    return GroupComponentIterator<Entities, Components ...>(entities.begin(), handles, componentManager);
	}     

	GroupComponentIterator<Entities, Components ...> end()
	{
	    return GroupComponentIterator<Entities, Components ...>(entities.end(), handles, componentManager);
	}      
    };
}
