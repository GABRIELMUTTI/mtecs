#pragma once

#include "mtecs/typedef/Typedef.hpp"
#include "mtecs/component/Mask.hpp"
#include "mtecs/entity/Entity.hpp"
#include "mtecs/component/ComponentManager.hpp"
#include "mtecs/component/ComponentHandle.hpp"

#include <utl/memory/ArrayPool.hpp>

#include <tuple>
#include <vector>

namespace mtecs
{
    template<class Container, class ... Components>
    class GroupComponentIterator
    {
        typedef typename Container::const_iterator Iterator;

    private:
	Iterator containerIterator;
	std::tuple<ComponentHandle<Components>& ...> handles;
	uint currentIndex;
	const internal::ComponentManager& componentManager;

	template<uint N, class TFirst, class TSecond, class ... Rest>
	void setComponents(Entity* entity)
	{
	    setComponents<N, TFirst>(entity);
	    setComponents<N + 1, TSecond, Rest ...>(entity);
	}

	template<uint N, class TComponent>
	void setComponents(Entity* entity)
	{
	    auto handle = componentManager.getComponent<TComponent>();
	    std::get<N, ComponentHandle<Components>& ...>(handles) = handle;
	}

    public:
	GroupComponentIterator(Iterator containerIterator, std::tuple<ComponentHandle< Components>& ...> handles, const internal::ComponentManager& componentManager) :
	    containerIterator(containerIterator),
	    handles(handles),
	    componentManager(componentManager)
	{
 
	}

	bool operator == (const GroupComponentIterator& other) const { return containerIterator == other.containerIterator; }
	bool operator != (const GroupComponentIterator& other) const { return containerIterator != other.containerIterator; }
	Entity* operator * () { setComponents<0, Components ...>(*containerIterator); return *containerIterator; }
	void operator ++ () { containerIterator++; }
    };
}
