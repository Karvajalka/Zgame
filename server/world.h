#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <iostream>
#include "dvector.h"
extern int areaSize;

class Trigger
{
	
};

class Tile
{
	public:
		char base;
		bool block;
		Tile( bool a, char c )
		{
			base = c;
			block = a;
		}
};

class Area
{
	public:
		int id;
		std::vector< std::vector< Tile* > > tilemap;
		Tile* getTile( dVector pos );
		Area()
		{
			std::vector< Tile* > tiles( areaSize, (Tile*)NULL );
			for( int a = 0; a < areaSize; a++ )
				tilemap.push_back( tiles );
			for( int aY = 0; aY < areaSize; aY++ )
				for( int aX = 0; aX < areaSize; aX++ )
					tilemap[aX][aY] = new Tile( 0, '.' );

		}
};

class World
{
	public:
		std::vector < Area* > areaVec;
		void unloadArea( int a );
};

void printArea( int a, World * world );


#endif
