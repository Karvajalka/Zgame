#ifndef NETWORK_H
#define NETWORK_H

#include <string>

void sentToClient( int s, std::string message );
void checkNewConnection();
void checkRecieve();
void sendToAll( std::string message );

#endif
