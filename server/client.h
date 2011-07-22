#ifndef CLIENT_H
#define CLIENT_H

#include "SDL_net.h"
#include "dvector.h"
#include <string>
#include "world.h"

class Client
{
	public:
		TCPsocket clientSocket;
		dVector pos;
		std::string clientName;
		std::string recieveBuffer;
		void processRecieve();
		void processMove( std::string direction );
		void sendView();
		Area* area;
		void send( std::string message );
		Client()
		{
		pos = dVector( 20, 20 );
		}
};



#endif
