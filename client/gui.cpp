#include <vector>
#include <string>
#include "SDL.h"
#include "gui.h"
#include "SDL_print.h"

const int messageViewHeight = 8;
const int messageViewLength = 40;

extern SDL_Surface *screen;

std::vector< std::string > messageView;

void initializeGui()
{
	messageView.resize( messageViewHeight );
	messageView.clear();
}

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
	//message.copy( &messageView[rows - 1].c_str(), ( rows-1 )*messageViewLength, message.size() );
}

void printMessages()
{
	SDL_FillRect( SDL_GetVideoSurface(), NULL, 0 );
	for( int y = 0; y < messageViewHeight; y++ )
		writeDownAt( messageView[y], 1, y );
	SDL_Flip( screen );
}



