#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "read_configs.h"
#include "main.h"

bool readConfigs( engine * e )
{
	if( readSystemCfg() )
		std::cout << "System.cfg read" << std::endl;
	if( readColourCfg( &(e->grapMod.colours) ) )
		std::cout << "Colours read" << std::endl;
	if( readControlCfg( e ) )
		std::cout << "Controls read" << std::endl;
	return true;
}

bool readColourCfg( std::vector< SDL_Colour* > * colours )
{
	char buffer[ 256 ];
	int blue, green, red;
	
	std::string temp;
	std::fstream config;
	config.open( "colours.cfg" );
    
    int failSafe = 0;
    /*
     * To make sure it doesn't just keep reading the file on and on, if
     * there is no "end" in the end of the file. It reads only the first
     * 100 lines
     */
    while( failSafe < 100 )
    {
		failSafe++;
		
		config.getline( buffer, 256 );
		temp = buffer;
		
		if( temp == "end" )
			return true;
		
		config.getline( buffer, 256 );
		red = atoi( buffer );
		config.getline( buffer, 256 );
		green = atoi( buffer );
		config.getline( buffer, 256 );
		blue = atoi( buffer );
		SDL_Color * c = new SDL_Color;
		c->r = red;
		c->b = blue;
		c->g = green;
		
		//this should be there but it makes it crash???
		colours->push_back( c );
	}
}

bool readSystemCfg()
{

}

bool readControlCfg( engine * e )
{
	char buffer[256];
	std::string temp = "";
	std::fstream config;
	config.open( "config.cfg" );
    
	int failSafe = 0;
    /*
     * To make sure it doesn't just keep reading the file on and on, if
     * there is no "end" in the end of the file. It reads only the first
     * 100 lines
     */
	while ( failSafe < 100 )  
	{
		failSafe++;
		config.getline( buffer, 256 );
		temp = buffer;
		if( temp == "end" )
			return true;
		e->processInput( temp );
	}
}
