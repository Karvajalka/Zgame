#include <iostream>
#include "clientmodule.h"

void ClientModule::playerCheck()
{
	checkRecieve();
	//for( int x = 0; x < clientVec.size(); x++ )
		//clientVec[x]->sendView();
}

void ClientModule::newClient( SubNetworkModule * subNet )
{
	netMod->sentToClient( subNet->socket, "Welcome_visitor" ); 
	SDLNet_TCP_AddSocket( netMod->socketSet, subNet->socket );  // add the socket to socketSet
	Client * p = new Client();		//create new client and assign the socket to it, pushpack the client + socket to different lists
	p->clientMod = this;
	p->subNetMod = subNet;
	subNet->owner = p;
	p->area = worldMod->areaVec[0];
	clientVec.push_back( p );
	netMod->playerCount++;
}

void ClientModule::sendAll( std::string message )
{
	for( int x = 0; x < clientVec.size(); x++ )  
		SDLNet_TCP_Send( clientVec[x]->subNetMod->socket, message.c_str(), message.size() );
}


void ClientModule::playerQuit( Client * c )
{
	for( int x = 0; x < clientVec.size(); x++ )
	{
		if( clientVec[x] == c )
		{
			clientVec.erase( x + clientVec.begin() );
			SDLNet_TCP_DelSocket( netMod->socketSet, c->subNetMod->socket );
			delete c;
			return;
		}
	}
}

void ClientModule::checkRecieve()
{
	int activeSockets = SDLNet_CheckSockets( netMod->socketSet, 0);  // amount of sockets that should be ready
	for( int x = 0; x < clientVec.size(); x++ )
	{
		if( !activeSockets )  //stop when all active sockets have been handled
			return;
		if( clientVec[x]->subNetMod->checkRecieve() )
			activeSockets--; // decrease the amount of sockets that need to be handled
	}
}
