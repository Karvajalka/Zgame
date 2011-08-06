#ifndef MAIN_H
#define MAIN_H

#include "network.h"
#include "input.h"
class engine
{
	public:
		int direction;
		netModule netMod;
		inputModule inMod;
		
		void processInput( std::string input );
		void processRecieve( std::string message );
		
		void mainLoop();
};

class graphicModule
{
	public:
};



#endif
