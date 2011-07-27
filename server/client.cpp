#include <vector>
#include <iostream>
#include "client.h"
#include "string_ext.h"
#include "network.h"
#include "convert.h"

extern std::vector< Client* > clientVec;
int viewDistance = 10;

void playerCheck()
{
	for( int x = 0; x < clientVec.size(); x++ )
		clientVec[x]->sendView();
}

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
			std::string stuffSaid;
			for( int x = 1; x < words.size() ; x++ )
				stuffSaid += ( " " + words[x] );
			sendToAll( clientName + " says:" + stuffSaid + "\n" );
			std::cout << clientName << " says:" << stuffSaid << std::endl;
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
	sendBuffer = "!map\n";
	for( int x = 0 - viewDistance; x < viewDistance + 1; x++ )
	{
		for( int y = 0 - viewDistance; y < viewDistance + 1; y++ )
		{
			Tile* t = area->getTile( pos + dVector ( x,y ) );
			sendBuffer.push_back( t->base );
		}
		//sendBuffer.push_back( '\n' );
	}
	sendBuffer.push_back( '\n' );
	send( sendBuffer );
}

void Client::send( std::string str )
{
	SDLNet_TCP_Send( clientSocket, str.c_str(), str.size() );
}
