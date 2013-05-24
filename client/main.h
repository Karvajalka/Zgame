#ifndef MAIN_H
#define MAIN_H

#include <string>
#include <vector>

#include "network.h"
#include "input.h"
#include "graphics.h"

class engine
{
	public:
		bool running;
		int DELAY_AMOUNT;
		std::vector<std::string> messageBuffer;
		
		netModule netMod;
		inputModule inMod;
		graphicsModule grapMod;
		
		void processInput( std::string input );
		void processRecieve( );
		void start();
		
		void mainLoop();
		engine()
		{
			running = true;
			DELAY_AMOUNT = 20;
			messageBuffer.assign( 6, "" );
		}
};
#endif
