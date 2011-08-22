#ifndef CLIENTMODULE_H
#define CLIENTMODULE_H
#include "client.h"
#include "subnetwork.h"
#include "network.h"
#include "world.h"
#include <string>

class NetworkModule;
class Client;
class SubNetworkModule;
class WorldModule;

class ClientModule
{
	public:	
		std::vector< Client* > clientVec; //holds active clients
		NetworkModule* netMod;
		WorldModule* worldMod;
		void newClient( SubNetworkModule * subNet );
		void playerCheck();
		void sendAll( std::string message );
		void playerQuit( Client * c );
		void checkRecieve();
		
};

#endif
