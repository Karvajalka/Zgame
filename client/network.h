#ifndef NETWORK_H
#define NETWORK_H

#include <string>
#include "SDL_net.h"

class netModule
{
	public:
		bool recievedStuff;
		std::string recieveBuffer;
		
		int port;// port  = 2054;
		IPaddress ip;		// Server address
		const char* ipS;
		TCPsocket serverSocket;
		SDLNet_SocketSet set;
		
		int initConnection();
		void sendServer( std::string message );
		void checkRecieve();
		std::string recieveLine();
		netModule()
		{
			port = 2054;
			ipS = "127.0.0.1";
		}

};

void processRecieve( std::string message );
#endif
