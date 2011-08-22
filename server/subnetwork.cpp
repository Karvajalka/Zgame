#include <iostream>
#include <sstream>
#include "subnetwork.h"
#include "client.h"
#include "clientmodule.h"

void SubNetworkModule::sendTo( std::string str ) // send string to client
{
	std::string str2;
	std::stringstream out;
	out << str.size();
	str2 = out.str();
	for( ;str2.size() < 3; str2.insert( 0, "0" ) ){} // add 0, so that the number is 001, 021, 322 styled, always three chars
	SDLNet_TCP_Send( socket, str2.c_str(), str2.size() );
	SDLNet_TCP_Send( socket, str.c_str(), str.size() );
}

bool SubNetworkModule::checkRecieve()
{
	if ( SDLNet_SocketReady( socket ) )
	{	
		char buffer[3];
		if( SDLNet_TCP_Recv( socket, buffer, 3 ) > 0 )
		{
			std::istringstream intStream( buffer );
			int incPackSize = 0;
			intStream >> incPackSize;
		
			char newBuffer[ incPackSize ];
			SDLNet_TCP_Recv( socket, newBuffer, incPackSize );
			
			recieveBuffer = newBuffer;
			recieveBuffer.erase( incPackSize );
			
			//std::cout << recieveBuffer << "-" << recieveBuffer.size() << std::endl;
			
			if( owner != NULL)
				owner->processRecieve( recieveBuffer );
			else
				std::cout << "isnull" << std::endl;
				
			return true;
		}
		else   // if the client disconnected, remove him from all vectors/sets/lists
		{
			std::cout << "Client disconnected\n" ;
			owner->clientMod->playerQuit( owner );
			return true;
		}
	}
	return false;
}

