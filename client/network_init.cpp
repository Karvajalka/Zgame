#include <iostream>
#include <cstring>
#include <string>
#include "SDL_net.h"
#include "network_init.h"

const int port = 2054;
IPaddress ip;		/* Server address */
TCPsocket serverSocket;
SDLNet_SocketSet set;

int initConnection() 
{
	if ( SDLNet_Init() < 0 )
	{
		std::cout << "SDLNET_Init() failed, shutting down \n";
		return 0;
	}
 
	if ( SDLNet_ResolveHost( &ip, "127.0.0.1" , port ) < 0 )
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
