#include <iostream>
#include <cstring>
#include <string>
#include "network_init.h"

#include "SDL_net.h"

TCPsocket listenSocket;
SDLNet_SocketSet socketSet;

const int port = 2054;
const int maxPlayers = 8;

bool initNetwork()
{
	IPaddress ip;
	if ( SDLNet_Init() < 0 )
	{
		std::cout << "SDLNET_Init() failed, shutting down \n";
		return 0;
	}

	if ( SDLNet_ResolveHost( &ip, NULL, port ) < 0 )
	{
		std::cout << "Failed to resolve host, shutting down \n";
		return 0;
	}

	if ( !( listenSocket = SDLNet_TCP_Open( &ip ) ) )
	{
		std::cout << "Failed to open socket, shutting down \n";
		return 0;
	}
	socketSet = SDLNet_AllocSocketSet( maxPlayers );  //avaliable socketSpots

	return 1;
}

