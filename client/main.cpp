#include <iostream>

#if defined(WIN32)

#include <windows.h>

#endif

#include "SDL.h"
#include "main.h"
#include "SDL_init.h"
#include "SDL_print.h"
#include "read_configs.h"
#include "gui.h"
#include "map.h"


engine gameEngine;
extern SDL_Surface *screen;

const int DELAY_AMOUNT = 20;
bool running = 1;

#if defined(WIN32)

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR
lpCmdLine, int nCmdShow )

#else

int main()

#endif

{
	std::cout << "Starting" << std::endl;
	
	if( !init_SDL() )
		return 0;
	std::cout << "SDL initializedl" << std::endl;
	
	if( gameEngine.netMod.initConnection() == -1 )
	{
		std::cout << "failed to establish connection" << std::endl;
		return 0;
	}
	std::cout << "Connection established" << std::endl;
	initializeMap();
	//initializeGui();
   //if( read_configs )
      //return 0;
	close_SDL();
	return 1;
}

void engine::mainLoop()
{
	while( running ) //main loop
	{
		netMod.checkRecieve();
		if( netMod.recievedStuff )
		{
			processRecieve( netMod.recieveBuffer );
			netMod.recieveBuffer.clear();
			netMod.recievedStuff = false;
		}
		inMod.getInput();
		if( inMod.gotInput )
		{
			processRecieve( inMod.inputBuffer );
			inMod.inputBuffer.clear();
			inMod.gotInput = false;
		}
		SDL_Delay( DELAY_AMOUNT );
		renderView();
	}
}

void engine::processInput( std::string input )
{
	std::cout << input << std::endl;
	netMod.sendServer( input + "\n" );
}

void engine::processRecieve( std::string message )  //figures out what to do with the recieved stuff
{
	std::cout << message << std::endl;
	if( message == "!map" )
	{
		updateMap( netMod.recieveLine() );
	}
	//newMessage( message );
	//printMessages();
	//writeDownAt( message, 0,0 );
	//std::cout << message << std::endl;
}
