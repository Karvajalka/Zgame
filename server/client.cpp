#include <vector>
#include <iostream>
#include "client.h"
#include "string_ext.h"
#include "network.h"
#include "convert.h"

int viewDistance = 10;

void Client::processMove( std::string direction )
{
	dVector newPos = pos + convertMoveCommand( direction );
	if( !area->getTile( newPos )->block )
		pos = newPos;
}

void Client::processRecieve()
{
	std::vector<std::string> words = dismemberString( recieveBuffer );
	if( words.size() > 0 )
	{
		words.push_back( "" );
		if( words[0][0] == '/' )  // / means it's a command or something
		{
			if( words[0] == "/name" )
				clientName = words[1];
		}
		else if( words[0] == "say" ) // it thinks it's a chat message
		{
			sendToAll( clientName + " says:" + recieveBuffer + "\n" );
			std::cout << clientName << " says:" << recieveBuffer << std::endl;
		}
		else if( words[0] == "move" )
		{
			processMove( words[1] );
		}
	}
}

void Client::sendView()
{
	std::string sendBuffer;
	sendBuffer.clear();
	for( int x = 0 - viewDistance; x < viewDistance + 1; x++ )
	{
		for( int y = 0 - viewDistance; x < viewDistance + 1; x++ )
		{
			Tile* t = area->getTile( pos + dVector ( x,y ) );
			sendBuffer.push_back( t->base );
		}
		sendBuffer.push_back( '\n' );
	}
	send( sendBuffer );
}

void Client::send( std::string str )
{
	SDLNet_TCP_Send( clientSocket, str.c_str(), str.size() );
}
