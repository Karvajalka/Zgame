#ifndef CLIENT_H
#define CLIENT_H

#include "subnetwork.h"
#include "dvector.h"
#include <string>


class ClientModule;
class Area;

class Client
{
	public:
		SubNetworkModule * subNetMod;
		ClientModule * clientMod;
		
		dVector position;
		std::string clientName;
		void processRecieve( std::string recieveBuffer );
		void processMove( std::string direction );
		void sendView();
		Area* area;
		void send( std::string message );
		Client( )
		{
			position = dVector( 11, 11 );
		}
};


#endif
