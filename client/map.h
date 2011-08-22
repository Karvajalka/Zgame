#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include "dvector.h"

class Map
{
	public:
		std::vector< std::vector< char > > mapArray;
		std::vector< dVector > blinkers;
		int viewSize;
		int rotation;
};

void initializeMap( Map * map );
void updateMap( std::string newView, Map * map );

#endif
