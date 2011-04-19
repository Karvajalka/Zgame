#include <iostream>
#include "network.h"
#include "SDL_print.h"
#include "SDL_net.h"

extern TCPsocket serverSocket;
extern SDLNet_SocketSet set;

void sendServer( std::string message )
{
	SDLNet_TCP_Send( serverSocket, message.c_str(), message.size() );
}

void checkRecieve()
{
	static std::string recieveBuffer;
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
				processRecieve( recieveBuffer );
				recieveBuffer.clear();
				return;
			}
		}
	}
}

void processRecieve( std::string message )
{
	std::cout << message << std::endl;
}
