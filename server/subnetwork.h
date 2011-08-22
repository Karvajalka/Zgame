#ifndef SUBNETWORK_H
#define SUBNETWORK_H
#include <string>
#include "SDL_net.h"

class Client;

class SubNetworkModule
{
	public:
		Client * owner;
		std::string recieveBuffer;
		TCPsocket socket;
		bool checkRecieve();
		void sendTo( std::string str );
		SubNetworkModule()
		{
			owner = NULL;
		}
};


/* So, the idea, we have a ClientModule, that handles creating new clients and their network stuff. End.
 * 
 * 
 * 
 * 
 * 
 */




#endif
