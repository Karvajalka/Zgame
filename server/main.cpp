#include "main.h"
#include "network_init.h"
#include "network.h"
#include "world.h"
#include <iostream>

#if defined(WIN32)

#include <windows.h>

#endif

int main()
{
	if ( !initNetwork() )
		return 0;
	World * world = new World;
	world->loadArea( 1, 2 );
	world->areaVec[0]->x = 9;
	//Area * area = new Area;
	//area->x = 2;
	//area->y = 2;
	//world->areaVec.push_back( area );
	printArea( 0, world );
	world->saveArea( 0 );
	while ( true )  //mainloop
	{
		checkNewConnection(); //check for incoming connections
		checkRecieve();  //check for incoming stuff
	}
}
