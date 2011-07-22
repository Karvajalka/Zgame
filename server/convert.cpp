#include "convert.h"

dVector convertMoveCommand( std::string cmd )
{
	if( cmd == "north" )
		return dVector(0,-1);
	else if( cmd == "south" )
		return dVector(0,1);
	else if( cmd == "east" )
		return dVector(1,0);
	else if( cmd == "west" )
		return dVector(-1,0);
	else if( cmd == "northwest" )
		return dVector(-1,-1);
	else if( cmd == "southeast" )
		return dVector(1,1);
	else if( cmd == "northeast" )
		return dVector(-1,1);
	else if( cmd == "southwest" )
		return dVector(1,-1);
	else
		return dVector(0,0);
}
