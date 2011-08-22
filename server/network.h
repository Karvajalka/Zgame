#ifndef NETWORK_H
#define NETWORK_H

#include <string>
#include <vector>
#include "SDL_net.h"
#include "subnetwork.h"

class ClientModule;

class NetworkModule
{
	public:
		TCPsocket listenSocket;
		SDLNet_SocketSet socketSet;
		IPaddress ip;
		
		std::vector< SubNetworkModule > connections;
		ClientModule * clientMod;
		
		int port;
		int maxPlayers;
		int playerCount;
		
		bool initNetwork();
		void checkNewConnection();
		void sentToClient( TCPsocket theclient, std::string message );
		
		NetworkModule()
		{
			port = 2054;
			maxPlayers = 8;
			playerCount = 0;
		}
};
#endif
