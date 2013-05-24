#include <iostream>
#include <sstream>
#include <cstring>
#include "network.h"

int netModule::initConnection() 
{
	if ( SDLNet_Init() < 0 )
	{
		std::cout << "	-SDLNET_Init() failed, shutting down \n";
		return 0;
	}
 
	if ( SDLNet_ResolveHost( &ip, ipS , port ) < 0 )
	{
		std::cout << "	-Failed to resolve host, shutting down \n";
		return 0;
	}
        if ( !( serverSocket = SDLNet_TCP_Open(&ip) ) )
	{
		std::cout << "	-Failed to open socket, shutting down \n";
		return 0;
	}
	set = SDLNet_AllocSocketSet( 1 );
	SDLNet_TCP_AddSocket( set, serverSocket );
	gotConnection = true;
	return gotConnection;
}

void netModule::sendServer( std::string message )  //sends the string message to the server
{
	if( gotConnection )
	{
		std::string str;
		std::stringstream out;
		out << message.size();
		str = out.str();
		for( ;str.size() < 3; str.insert( 0, "0" ) ){}
		
		SDLNet_TCP_Send( serverSocket, str.c_str(), str.size() );
		SDLNet_TCP_Send( serverSocket, message.c_str(), message.size() );
		
		std::cout << str << ": " << message << std::endl;
	}
}

void netModule::recieve()
{
	if( SDLNet_CheckSockets( set, 0 ) )
	{
		if( SDLNet_SocketReady( serverSocket ))
		{
			char buffer[4];
			SDLNet_TCP_Recv( serverSocket, buffer, 3 );
			
			std::istringstream intStream( buffer );
			int incPackSize = 0;
			intStream >> incPackSize;
			
			char newBuffer[ incPackSize + 1 ];
			SDLNet_TCP_Recv( serverSocket, newBuffer, incPackSize );
			
			recieveBuffer.clear();
			recieveBuffer = newBuffer;
			recievedStuff = true;
			return;
		}
	}
}

