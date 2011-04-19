#include "convert.h"

void convertMoveCommand( int & deltaX, int & deltaY, std::string cmd )
{
	if( cmd == "north" )
	{
		deltaX = 0;
		deltaY = -1;
		return;
	}
	else if( cmd == "south" )
	{
		deltaX = 0;
		deltaY = 1;
		return;
	}
	else if( cmd == "east" )
	{
		deltaX = 1;
		deltaY = 0;
		return;
	}
	else if( cmd == "west" )
	{
		deltaX = -1;
		deltaY = 0;
		return;
	}
	else if( cmd == "northwest" )
	{
		deltaX = -1;
		deltaY = -1;
		return;
	}
	else if( cmd == "southeast" )
	{
		deltaX = 1;
		deltaY = 1;
		return;
	}
	else if( cmd == "northeast" )
	{
		deltaX = 1;
		deltaY = -1;
		return;
	}
	else if( cmd == "southwest" )
	{
		deltaX = -1;
		deltaY = 1;
		return;
	}
	else
	{
		deltaX = 0;
		deltaY = 0;
		return;
	}
}
