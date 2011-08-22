#include <iostream>

#if defined(WIN32)

#include <windows.h>

#endif

#include "main.h"
#include "read_configs.h"
#include "stringExt.h"

#if defined(WIN32)

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR
lpCmdLine, int nCmdShow )

#else

int main()

#endif

{
	engine * game = new engine();
	readConfigs( game );
	game->start();
	game->grapMod.close_SDL();
	return 1;
}

void engine::start()
{
	std::cout << "Starting" << std::endl;
	
	if( !grapMod.init_SDL() )
		return;
		
	std::cout << "SDL initializedl" << std::endl;
	
	if( netMod.initConnection() == -1 )
	{
		std::cout << "failed to establish connection" << std::endl;
		return;
	}
	std::cout << "Connection established" << std::endl;
	
	initializeMap( &grapMod.defaultView );
	
	mainLoop();
}

void engine::mainLoop()
{
	while( running ) //main loop
	{
		netMod.recieve();
		if( netMod.recievedStuff )
		{
			processRecieve( netMod.recieveBuffer );
			netMod.recieveBuffer.clear();
			netMod.recievedStuff = false;
		}
		inMod.getInput();
		if( inMod.gotInput )
		{
			processInput( inMod.inputBuffer );
			inMod.inputBuffer.clear();
			inMod.gotInput = false;
		}
		SDL_Delay( DELAY_AMOUNT );
		grapMod.update();
	}
}

std::string whatDir( int rot )
{
	switch( rot )
	{
		case 0:
			return "north";
		case 1:
			return "northeast";
		case 2:
			return "east";		
		case 3:
			return "southeast";
		case 4:
			return "south";
		case 5:
			return "southwest";
		case 6:
			return "west";		
		case 7:
			return "northwest";
	}
}

void engine::processInput( std::string input )
{
	std::vector< std::string > words = dismemberString( input );
	/*
	 * All the words starting with % are checked for if they are bound to
	 * something, and then replaced with what there were bound to. If 
	 * nothing is found, the word is left as it is(currently without the
	 * % char though
	 */
	for( int x = 0; x < words.size(); x++ )
	{
		if( words[x][0] == '%' )
		{
			words[x].erase(0);
			std::string temp = inMod.checkForBind( words[x] );
			if( temp != "" )
				words[x] = temp;
		}
	}
	
	if( words[0][0] == '/' )
	{
		if( words[0] == "/bind" )
			if( words.size() > 2 )
				inMod.addBind( words[1], words[2] );
		else if( input == "/quit" )
			running = false;
	}
	else if( input == "a" )
	{
		if( grapMod.defaultView.rotation > 0 )
			grapMod.defaultView.rotation--;
		else
			grapMod.defaultView.rotation = 7;
			std::cout << grapMod.defaultView.rotation << std::endl;
	}
	else if( input == "d" )
	{
		if( grapMod.defaultView.rotation < 7 )
			grapMod.defaultView.rotation++;
		else
			grapMod.defaultView.rotation = 0;
			std::cout << grapMod.defaultView.rotation << std::endl;
	}
	else if( input == "w" )
	{
		std::string temp = "move " + whatDir( grapMod.defaultView.rotation );
		netMod.sendServer( temp );
	}
	else
	{
		netMod.sendServer( input );
	}
}

void engine::processRecieve( std::string message )  //figures out what to do with the recieved stuff
{
	//std::cout << message << std::endl;
	if( message == "!map" )
	{
		netMod.recieve();
		updateMap( netMod.recieveBuffer, &grapMod.defaultView );
		if( grapMod.defaultView.rotation > 0 && grapMod.defaultView.rotation < 8 )
		{
			grapMod.rotate( &grapMod.defaultView );
		}
	}
	//newMessage( message );
	//printMessages();
	//writeDownAt( message, 0,0 );
	//std::cout << message << std::endl;
}
