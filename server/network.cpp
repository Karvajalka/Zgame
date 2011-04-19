#include <iostream>
#include <vector>
#include "network.h"
#include "SDL_net.h"
#include "client.h"

extern SDLNet_SocketSet socketSet;
extern TCPsocket listenSocket;
std::vector< TCPsocket > clientSockets;  //list of all active sockets
std::vector< Client* > clientVec;

int playerCount = 0;

void sentToClient( TCPsocket theclient, std::string str ) // send string to client
{
	SDLNet_TCP_Send( theclient, str.c_str(), str.size() );
}

void checkNewConnection()
{
	TCPsocket cSocket; // client connects to this socket
	IPaddress *remoteIP;
	if( cSocket = SDLNet_TCP_Accept( listenSocket ) )
	{
		if( remoteIP = SDLNet_TCP_GetPeerAddress( cSocket ) )
			std::cout << "Host connected:" << SDLNet_Read32(&remoteIP->host) << "::" << SDLNet_Read16(&remoteIP->port) << std::endl;
		else
			std::cout << "SDLNet_TCP_GetPeerAddress:" << SDLNet_GetError() << std::endl;

		sentToClient( cSocket, "Welcome_visitor\n" ); 
		SDLNet_TCP_AddSocket( socketSet, cSocket );  // add the socket to socketSet
		Client * p = new Client;		//create new client and assign the socket to it, pushpack the client + socket to different lists
		p->clientSocket = cSocket;
		clientVec.push_back( p );
		clientSockets.push_back( cSocket );
		playerCount++;
	}
}

void checkRecieve()
{
	int activeSockets = SDLNet_CheckSockets( socketSet, 0);  // amount of sockets that should be ready
	for( int sockNum = 0; sockNum < clientSockets.size(); sockNum++ )
	{
		if ( SDLNet_SocketReady( clientSockets[sockNum] ) )
		{
			activeSockets--; // decrease the amount of sockets that need to be handled
			char buffer[2];
			if ( SDLNet_TCP_Recv( clientSockets[sockNum], buffer, 1 ) > 0 )  //recieving something 1 byte at a time
			{
				if( buffer[0] != '\n' )   //recieve ends at a newline char, keep pushing back to recievebuffer until we encounter one
					clientVec[ sockNum ]->recieveBuffer.push_back( buffer[0] );
				else
				{
					clientVec[ sockNum ]->processRecieve();
					clientVec[ sockNum ]->recieveBuffer.clear(); // clear the buffer for new recieve
				}
			}
			else   // if the client disconnected, remove him from all vectors/sets/lists
			{
				std::cout << "Client disconnected\n" ;
				SDLNet_TCP_DelSocket( socketSet, clientSockets[sockNum] );
				delete clientVec[ sockNum ];
				clientVec.erase( clientVec.begin() + sockNum );
				clientSockets.erase( clientSockets.begin() + sockNum );
			}
			if( !activeSockets )  //stop when all active sockets have been handled
				return;
		}
	}
}

void sendToAll( std::string message )   // iterates all the connected clients and sends the message
{
	for( int x = 0; x < clientSockets.size(); x++ )  
		SDLNet_TCP_Send( clientVec[x]->clientSocket, message.c_str(), message.size() );
}

