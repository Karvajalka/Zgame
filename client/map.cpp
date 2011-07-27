#include <iostream>
#include "map.h"
#include "SDL_print.h"

const int viewSize = 21;
Map defaultView;

void initializeMap()
{
	std::cout << "initializing map" << std::endl;
	
	std::vector< char > tiles;
	tiles.insert(  tiles.begin(), viewSize, '#' );
	defaultView.mapArray.resize( viewSize );
	
	for( int x = 0; x < viewSize; x++ )
		defaultView.mapArray[x] = tiles;
}

void printMap()
{
	for( int x = 0; x < viewSize; x++ )
	{
		for( int y = 0; y < viewSize; y++ )
		{
			std::string temp;
			temp.push_back( defaultView.mapArray[x][y] );
			writeDownAt( temp,  x,  y );
		}
	}
}

void updateMap( std::string newView )
{
	int a = newView.size();
	for( int x = 0; x < viewSize; x++ )
	{
		for( int y = 0; y < viewSize; y++ )
		{
			if( x + y*viewSize < a )
				defaultView.mapArray[x][y] = newView[ x + y*viewSize ];
		}
	}
	defaultView.updated = 1;
}
