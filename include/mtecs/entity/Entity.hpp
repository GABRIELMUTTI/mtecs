#pragma once

#include "mtecs/typedef/Typedef.hpp"
#include "mtecs/component/Mask.hpp"
#include "mtecs/component/ComponentManager"

#include <string>

namespace mtecs
{
    class Entity
    {	
    private:
	uint id;
	std::string name;
	Mask mask;

	internal::ComponentManager& componentManager;

    public:
	Entity(uint id, const std::string& name, internal::ComponentManager& componentManager);

	uint getId() const;
	std::string getName() const;
	Mask getMask() const;

	bool hasComponents(const Mask& componentMask) const;
	void setMask(const Mask& mask);
	
	template<class T>
	inline auto getComponent()
	{
	    return componentManager.getComponent<T>(id);
	}

	template<class T>
	inline auto addComponent()
	{
	    return componentManager.addComponent<T>(id);
	}

	template<class T>
	inline void removeComponent()
	{
	    componentManager.removeComponent<T>(id);
	}
    };
}
