#include <iostream>
#include <sstream>
#include "network.h"
#include "client.h"
#include "clientmodule.h"

void NetworkModule::sentToClient( TCPsocket theClient, std::string str ) // send string to client
{
	std::string str2;
	std::stringstream out;
	out << str.size();
	str2 = out.str();
	for( ;str2.size() < 3; str2.insert( 0, "0" ) ){} // add 0, so that the number is 001, 021, 322 styled, always three chars
	SDLNet_TCP_Send( theClient, str2.c_str(), str2.size() );
	SDLNet_TCP_Send( theClient, str.c_str(), str.size() );
}

void NetworkModule::checkNewConnection()
{
	SubNetworkModule * subNet = new SubNetworkModule;
	IPaddress *remoteIP;
	if( subNet->socket = SDLNet_TCP_Accept( listenSocket ) )
	{
		if( remoteIP = SDLNet_TCP_GetPeerAddress( subNet->socket ) )
			std::cout << "Host connected:" << SDLNet_Read32(&remoteIP->host) << "::" << SDLNet_Read16(&remoteIP->port) << std::endl;
		else
			std::cout << "SDLNet_TCP_GetPeerAddress:" << SDLNet_GetError() << std::endl;

		clientMod->newClient( subNet );
	}
}

bool NetworkModule::initNetwork()
{
	if ( SDLNet_Init() < 0 )
	{
		std::cout << "SDLNET_Init() failed, shutting down \n";
		return 0;
	}

	if ( SDLNet_ResolveHost( &ip, NULL, port ) < 0 )
	{
		std::cout << "Failed to resolve host, shutting down \n";
		return 0;
	}

	if ( !( listenSocket = SDLNet_TCP_Open( &ip ) ) )
	{
		std::cout << "Failed to open socket, shutting down \n";
		return 0;
	}
	socketSet = SDLNet_AllocSocketSet( maxPlayers );  //avaliable socketSpots

	return 1;
}
