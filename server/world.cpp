#include "world.h"
#include <fstream>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <stdio.h>

int areaSize = 63; // 2 must not divide areasize

Tile* Area::getTile( dVector pos )
{
	return tilemap[ pos.x ][ pos.y ];//must take the module too, no net so idk how, 
}

void World::unloadArea( int a )
{			
	delete areaVec[ a ];
	areaVec.erase( areaVec.begin() + a );
	return;
}

void printArea( int a, World * world )
{
	Area * area = world->areaVec[a];
	for( int aY = 0; aY < areaSize; aY++ )
	{
		for( int aX = 0; aX < areaSize; aX++ )
			std::cout << area->tilemap[aX][aY]->base;
		std::cout<<std::endl;
	}

}

