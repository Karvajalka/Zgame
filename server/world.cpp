#include "world.h"
#include <fstream>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <stdio.h>

int areaSize = 63; // 2 must not divide areasize

Tile* Area::getTile( int x, int y )
{
	x += ( areaSize - 1 )/2;
	y += ( areaSize - 1 )/2;
	return tilemap[x ][ y ];//must take the module too, no net so idk how, 
}

Tile* World::getTile( int x, int y )
{
	int areaPos[2]; // x,y pos
	areaPos[0] = x / areaSize;
	areaPos[1] = y / areaSize;
	for( int a = 0; a < areaVec.size(); a++ )
	{
		Area* area = areaVec[a];
		if( area->x == areaPos[0] && area->y == areaPos[1] )
		{
			return area->getTile( x, y );
		}
	}
	loadArea( areaPos[0], areaPos[1] ); 
	return areaVec[ areaVec.size() - 1 ]->getTile( x, y ); // the tile is in the newly loaded area, which is the last one in the area list

}

int findPosDat( int x, int y )
{
	int position = 0;
	std::fstream aRef;
	aRef.open ( "areas_ref.dat", std::fstream::in | std::fstream::binary );
	while( !aRef.eof() )
	{
		char bufferA[256];
		char bufferB[256];
		aRef.getline( bufferA, 256 );
		aRef.getline( bufferB, 256 );
		if( atoi( bufferA ) == x && atoi( bufferB ) == y )
		{
			aRef.close();
			return position;
		}
		position++;
	}
	aRef.close();
	return -1;
}


bool World::loadArea( int x, int y )
{
	std::fstream aStr;
	aStr.open ("areas.dat", std::fstream::in | std::fstream::binary );
	int aPos = findPosDat( x, y );
	if( aPos != -1 )
	{
		Area * area = new Area();
		area->x = x;
		area->y = y;
		aStr.seekg( aPos * ( areaSize * areaSize + 1 ) );
		char bufferD[ areaSize * areaSize ];
		aStr.readsome( bufferD, areaSize*areaSize );
		aStr.close();
		for( int aY = 0; aY < areaSize; aY++ )
			for( int aX = 0; aX < areaSize; aX++ )
				area->tilemap[aX][aY]->base = bufferD[ aX + areaSize*aY];
			
		areaVec.push_back( area );
		return true;
	}
	aStr.close();
	return false;
}


void World::unloadArea( int a )
{
	saveArea( a );			
	delete areaVec[ a ];
	areaVec.erase( areaVec.begin() + a );
	return;
}

void World::saveArea( int a )
{
	int aPos = findPosDat( areaVec[a]->x, areaVec[a]->y );
	std::string buffer;
	buffer.clear();
	for( int aY = 0; aY < areaSize; aY++ )
		for( int aX = 0; aX < areaSize; aX++ )
			buffer.push_back( areaVec[a]->tilemap[aX][aY]->base );

	//buffer += "\n";

	std::fstream aStr;
	if( aPos != -1 )
	{
		aStr.open("areas.dat", std::fstream::out|std::fstream::in );
		aStr.seekg( ( aPos * ( areaSize * areaSize + 1 )  )  , std::ios::beg );
		aStr.seekp( ( aPos * ( areaSize * areaSize + 1 )  )  , std::ios::beg );
	}
	else
	{
		std::fstream aRef;
		aStr.open ("areas.dat", std::fstream::app | std::fstream::out | std::fstream::binary );
		aRef.open ( "areas_ref.dat", std::fstream::app | std::fstream::out | std::fstream::binary  );
		aRef.seekg ( 0, std::ios::end );
		aStr.seekg( 0, std::ios::end );
		std::string info;
		char temp[256];
		sprintf ( temp, "%d\n%d\n", areaVec[a]->x ,areaVec[a]->y );
		info += temp;
		aRef << info;;
		aRef.close();
	}	
	aStr << buffer;
	aStr.close();
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

