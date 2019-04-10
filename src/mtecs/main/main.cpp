#include <iostream>

#include "mtecs/world/World.hpp"
#include "mtecs/system/BaseSystem.hpp"
#include <utl/memory/GenericHandle.hpp>

#include <ctime>

using namespace std;
using namespace mtecs;
using namespace mtecs::internal;

const uint numEntities = 100000000;

class AComponent : public Component
{
public:
    AComponent()
    {
	
    }
	
    int a;
    int b;
    int c;
};

class StressSystem : public BaseSystem
{
public:
    Group* group;
    
    StressSystem(uint id) : BaseSystem(id)
    {
	
    }
    
    void initialize()
    {
	group = getGroup<AComponent>();

	for (uint i = 0; i < numEntities; i++)
	{
	    Entity& e = createEntity("ok");
	    auto handle = e.addComponent<AComponent>();

	    handle->a = 0;
	    handle->b = 0;
	    handle->c = 0;
	    
	}
    }
    
    void update(float deltaTime)
    {
	for (Entity* e : group->getEntities1())
	{

	    auto handle = e->getComponent<AComponent>();
	    uint tmp = handle->a;
	    handle->a = handle->b;
	    handle->b = handle->c;
	    handle->c = tmp;
	}


    }
};

int main()
{

    World world = World("a world");


    world.addSystem<StressSystem>();

    uint frames = 0;
    std::clock_t start;
    double duration;

    start = std::clock();
    while(true)
    {
	world.update(0.0f);
	frames++;

	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

	if (duration >= 1)
	{
	    start = std::clock();
	    cout << "...fps: " << (int)(frames / duration) << endl;
	    frames = 0;
	}
    }

    return 0;
}
