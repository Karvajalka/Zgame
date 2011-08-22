#include <iostream>
#include "map.h"
#include "graphics.h"

const int viewSize = 21;

void initializeMap( Map * map )
{
	std::vector< char > tiles;
	tiles.insert(  tiles.begin(), viewSize, '.' );
	map->mapArray.resize( viewSize );
	map->viewSize = viewSize;
	map->rotation = 0;
	for( int x = 0; x < viewSize; x++ )
		map->mapArray[x] = tiles;
	std::cout << "map initialized " << std::endl;
}

void updateMap( std::string newView, Map * map )
{
	int a = newView.size();
	for( int y = 0; y < viewSize; y++ )
	{
		for( int x = 0; x < viewSize; x++ )
		{
			if( x + y*viewSize < a )
				map->mapArray[y][x] = newView[ x + y*viewSize ];
		}
	}
}
