#include <iostream>
#include "network.h"
#include "SDL_print.h"
#include "SDL_net.h"
#include "gui.h"

extern TCPsocket serverSocket;
extern SDLNet_SocketSet set;

void sendServer( std::string message )  //sends the string message to the server
{
	SDLNet_TCP_Send( serverSocket, message.c_str(), message.size() );
}

void checkRecieve()  //checks if there is something to recieve and recives it in parts
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

void processRecieve( std::string message )  //figures out what to do with the recieved stuff
{
	newMessage( message );
	printMessages();
	//writeDownAt( message, 0,0 );
	//std::cout << message << std::endl;
	
}
