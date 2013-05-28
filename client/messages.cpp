#include <vector>
#include "messages.h"

/*
const int messageViewHeight = 20;
const int messageViewLength = 40;
const int messageXdelta = 24;
std::vector< std::string > messageView;

void newMessage( std::string message )
{
	int rows = 1;
	int a = message.size();
	while( a > messageViewLength )  // calculates how many new rows will be added
	{
		rows++;
		a -= messageViewLength;
	}
	
	for( int x = messageViewHeight - 1; x > rows-1; x-- )  // moves all the messages down by the amount of to be added rows
		messageView[x] = messageView[x-rows];

	for( int x = 0; x < rows; x++ )  //copies the new message there;
		messageView[x] = message.substr ( x*messageViewLength, messageViewLength );
}

void printMessages()
{
	chatBox.fillColour( chatBox.baseColour );
	//fillRect( messageRect, 100, 100, 100 );
	for( int y = 0; y < messageViewHeight; y++ )
		chatBox.printText( messageView[y], 0, y );
		//writeDownAt( messageView[y], messageXdelta, y );
	SDL_Flip( screen );
}*/

void chatClass::updateChat( std::string s )
{
	int neededRows = s.size()/width + 1;
	for( int i = 0; i < neededRows; i++ )
	{
		char buffer[width];
		int length = width;
		if( length == neededRows - 1 )
			length = s.size() - neededRows*width;
		s.copy( buffer, length, i*width );
		int slot = (newest - neededRows + i);
		slot = slot%height;
		chatText[ 0 ] = buffer;
	}
	newest = (neededRows+newest)%height;
}
