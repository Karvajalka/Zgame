#ifndef CLIENT_H
#define CLIENT_H

#include "SDL_net.h"
#include <string>
#include "world.h"

class Client
{
	public:
		TCPsocket clientSocket;
		int xp, yp;
		std::string clientName;
		std::string recieveBuffer;
		void processRecieve();
		void processMove( std::string direction );
		void sendView();
		World* world;
		void send( std::string message );
};



#endif
