#include <iostream>
#include <cstring>
#include "network.h"
#include "SDL_print.h"
#include "SDL_net.h"
#include "gui.h"
#include "messages.h"
#include "map.h"

int netModule::initConnection() 
{
	if ( SDLNet_Init() < 0 )
	{
		std::cout << "SDLNET_Init() failed, shutting down \n";
		return 0;
	}
 
	if ( SDLNet_ResolveHost( &ip, ipS , port ) < 0 )
	{
		std::cout << "Failed to resolve host, shutting down \n";
		return 0;
	}
        if ( !( serverSocket = SDLNet_TCP_Open(&ip) ) )
	{
		std::cout << "Failed to open socket, shutting down \n";
		return 0;
	}
        set = SDLNet_AllocSocketSet( 1 );
        SDLNet_TCP_AddSocket( set, serverSocket );
        return 1;
}

void netModule::sendServer( std::string message )  //sends the string message to the server
{
	SDLNet_TCP_Send( serverSocket, message.c_str(), message.size() );
}

void netModule::checkRecieve()  //checks if there is something to recieve and recives it in parts
{
	if( SDLNet_CheckSockets( set, 0) )
	{
		if( SDLNet_SocketReady( serverSocket ))
		{
			char buffer[2];
			SDLNet_TCP_Recv( serverSocket, buffer, 1 );
			if( buffer[0] != '\n' )
				recieveBuffer.push_back( buffer[0] );
			else
			{
				recievedStuff = true;
				return;
			}
		}
	}
}

std::string netModule::recieveLine()
{
	char buffer[2];
	std::string recieved;
	while( true )
	{
		SDLNet_TCP_Recv( serverSocket, buffer, 1 );
		if( buffer[0] != '\n' )
			recieved.push_back( buffer[0] );
		else
		{
			return recieved;
		}
	}
}
