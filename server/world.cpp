#include <fstream>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <stdio.h>

#include "world.h"

Voronoi::Voronoi( int xs, int ys )
{
	width = xs;
	height = ys;
	world.clear();
	world.assign( width*height, 0 );
	points = new std::vector<dVector>;
	points->clear();
}

int Voronoi::distance( dVector p1, dVector p2 )
{
	int a,b;
	a = abs( p1.x - p2.x );
	b = abs( p1.y - p2.y );
	
	return b+a;
}

void Voronoi::generateDiagram( std::vector< dVector > * usedPoints )
{
	for( int y = 0; y < height; y++ )
		for( int x = 0; x < width; x++ )
		{
			int closestDistance = height*width;
			int closest = 0;
			for( int i = 0; i < usedPoints->size(); i++ )
			{
				int pointDistance = distance( usedPoints->at(i), dVector( x, y) );
				if( pointDistance < closestDistance )
				{
					closestDistance = pointDistance;
					closest = i;
				}
			}
			world[ x + y*width ] = closest;
		}
}

void Voronoi::generatePoints( int amount )
{
	for( int a = 0; a < amount; a++ )
	{
		int x = rand()%width;
		int y = rand()%height;
		dVector d( x, y );
		points->push_back( d );
	}
}

Tile* Area::getTile( dVector pos )
{
	pos.x = pos.x%dim.x;
	pos.y = pos.y%dim.y;
	if( pos.x < 0 )
		pos.x = pos.x + dim.x;
	if( pos.y < 0 )
		pos.y = pos.y + dim.y;
	int iPos = pos.x + dim.x * pos.y;
	return tilemap[ iPos ];//must take the module to stay in bounds 
}

void WorldModule::unloadArea( int a )
{			
	delete areaVec[ a ];
	areaVec.erase( areaVec.begin() + a );
	return;
}

Area::Area( int xs, int ys )
{
	voro = new Voronoi( xs, ys );
	voro->generatePoints( xs*ys/450 );
	voro->generateDiagram( voro->points );
	std::cout<<voro->world[43]<< " " <<voro->world[2] << std::endl;
	dim( xs, ys );
	tilemap.resize( dim.x * dim.y );
		
	int size = xs*ys;	
	for( int aY = 0; aY < ys; aY++ )
		for( int aX = 0; aX < xs; aX++ )
		{
			int spot = voro->world[ aX + aY*xs ];
			
			if( spot == voro->world[ (aX + 1 + aY*xs)%size ]
			&& spot == voro->world[ (aX - 1 + aY*xs)%size ]
			&& spot == voro->world[ (aX + (aY + 1)*xs)%size ]
			&& spot == voro->world[ (aX + (aY - 1)*xs)%size ] )
				tilemap[aX + dim.x*aY] = new Tile( 0, '.' );
			else 
				tilemap[aX + dim.x*aY] = new Tile( 0, '+' );
		}
	std::cout<<"World generated" << std::endl;
}

void printArea( int a, WorldModule * world )
{
	Area * area = world->areaVec[a];
	for( int aY = 0; aY < area->dim.y; aY++ )
	{
		for( int aX = 0; aX < area->dim.x; aX++ )
			std::cout << area->getTile( dVector( aX, aY ) )->base;
		std::cout<<std::endl;
	}
}

