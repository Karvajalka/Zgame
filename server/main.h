#ifndef MAIN_H
#define MAIN_H

#include "network.h"
#include "client.h"
#include "clientmodule.h"
#include "world.h"

class MainModule
{
	public:
		NetworkModule netMod;
		WorldModule worldMod;
		ClientModule clientMod; 
		void start();
		
		MainModule()
		{
			clientMod.netMod = &netMod;
			netMod.clientMod = &clientMod;
			clientMod.worldMod = &worldMod;
		}
};


#endif
