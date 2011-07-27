#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include "dvector.h"

void initializeMap();
void printMap();
void updateMap( std::string newView );
class Map
{
	public:
		bool updated;
		std::vector< std::vector< char > > mapArray;
		std::vector< dVector > blinkers;
};


#endif
