#include <vector>
#include <iostream>
#include <sstream>
#include "client.h"
#include "clientmodule.h"
#include "world.h"
#include "string_ext.h"
#include "convert.h"

int viewDistance = 10;

void Client::processMove( std::string direction )
{
	dVector newPos = ( position + convertMoveCommand( direction  ) );
	if( !area->getTile( newPos )->block )
		position = newPos;
}

void Client::processRecieve( std::string recieveBuffer )
{
	std::cout <<recieveBuffer<<std::endl;
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
			clientMod->sendAll( clientName + " says:" + stuffSaid + "\n" );
			std::cout << clientName << " says:" << stuffSaid << std::endl;
		}
		else if( words[0] == "move" )
		{
			processMove( words[1] );
		}
		else if( words[0] == "x" )
		{
			 area->getTile( position )->base = '#';
		}
	}
}

void Client::sendView()
{
	std::string sendBuffer;
	send( "!map" );
	for( int x = 0 - viewDistance; x < viewDistance + 1; x++ )
	{
		for( int y = 0 - viewDistance; y < viewDistance + 1; y++ )
		{
			dVector thisPos(0,0);
			thisPos = thisPos + position + dVector(x,y);
			
			if( x == 0 && y == 0 )
				sendBuffer.push_back( '@' );
			else if( thisPos.x < 0 || thisPos.y < 0 || thisPos.x > area->dimensions.x || thisPos.y > area->dimensions.y )
				sendBuffer.push_back( ' ' );
			else
			{
				Tile* t = area->getTile( position + dVector ( x,y ) );
				sendBuffer.push_back( t->base );
			}
		}
	}
	
	
	sendBuffer[ ( viewDistance ) * ( viewDistance*2 +2 )  ] = '@';
	send( sendBuffer );
}

inline void Client::send( std::string message )
{
	subNetMod->sendTo( message );
}
