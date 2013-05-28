#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <iostream>
#include "dvector.h"

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

class Voronoi
{
	public:
		int width, height;
		std::vector< dVector > * points;
		std::vector< int > world;
		void generatePoints( int amount );
		void generateDiagram( std::vector< dVector > * usedPoints );
		int distance( dVector p1, dVector p2 );
		
		Voronoi( int xs, int ys );
};
		
		

class Area
{
	public:
		int id;
		dVector dim;
		std::vector< Tile* > tilemap;
		Tile* getTile( dVector pos );
		Voronoi * voro;
		Area( int xs, int ys );
};

class WorldModule
{
	public:
		std::vector < Area* > areaVec;
		void unloadArea( int a );
		
};

void printArea( int a, WorldModule * world );


#endif
