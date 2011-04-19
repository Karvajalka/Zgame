#ifndef WORLD_H
#define WORLD_H

#include <vector>

extern int areaSize;

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
		int x,y;
		std::vector< std::vector< Tile* > > tilemap;
		Tile* getTile( int x, int y);
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
		bool loadArea( int x, int y );
		void saveArea( int a );
		void unloadArea( int a );
		Tile* getTile( int x, int y );
};


int findPosDat( int x, int y );
void printArea( int a, World * world );


#endif
