#include <iostream>
#include "SDL.h"

#if defined(WIN32)

#include <windows.h>

#endif

#include "main.h"
#include "network.h"
#include "world.h"
#include "client.h"

const int DELAY_AMOUNT = 20;

#if defined(WIN32)

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR
lpCmdLine, int nCmdShow )

#else

int main()

#endif
{
	MainModule game;
	game.start();
}

void MainModule::start()
{
	if ( !netMod.initNetwork() )
		return;
	Area * a = new Area();
	worldMod.areaVec.push_back(a);
	worldMod.areaVec[0]->id = 9;
	printArea( 0, &worldMod );
	while ( true )  //mainloop
	{
		netMod.checkNewConnection(); //check for incoming connections
		clientMod.playerCheck();  // check player input and send view();
		SDL_Delay( DELAY_AMOUNT );
	}
}
