#include <iostream>
#include "SDL.h"

#if defined(WIN32)

#include <windows.h>

#endif

#include "main.h"
#include "network_init.h"
#include "network.h"
#include "world.h"

const int DELAY_AMOUNT = 20;

#if defined(WIN32)

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR
lpCmdLine, int nCmdShow )

#else

int main()

#endif
{
	if ( !initNetwork() )
		return 0;
	World * world = new World;
	Area * a = new Area();
	world->areaVec.push_back(a);
	world->areaVec[0]->id = 9;
	printArea( 0, world );
	while ( true )  //mainloop
	{
		checkNewConnection(); //check for incoming connections
		checkRecieve();  //check for incoming stuff
		SDL_Delay( DELAY_AMOUNT );
	}
}
