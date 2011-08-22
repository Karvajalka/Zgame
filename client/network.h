#ifndef NETWORK_H
#define NETWORK_H

#include <string>
#include "SDL_net.h"

class netModule
{
	public:
		bool recievedStuff;
		bool gotConnection;
		std::string recieveBuffer;
		
		int port;// port  = 2054;
		IPaddress ip;		// Server address
		const char* ipS;
		TCPsocket serverSocket;
		SDLNet_SocketSet set;
		
		int initConnection();
		void sendServer( std::string message );
		void recieve();

		netModule()
		{
			port = 2054;
			ipS = "127.0.0.1";
			gotConnection = false;
		}

};

void processRecieve( std::string message );

#endif
