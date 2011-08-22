#ifndef MAIN_H
#define MAIN_H

#include <string>
#include "network.h"
#include "input.h"
#include "graphics.h"

class engine
{
	public:
		bool running;
		int DELAY_AMOUNT;
		
		netModule netMod;
		inputModule inMod;
		graphicsModule grapMod;
		
		void processInput( std::string input );
		void processRecieve( std::string message );
		void start();
		
		void mainLoop();
		engine()
		{
			running = true;
			DELAY_AMOUNT = 20;
		}
};
#endif
