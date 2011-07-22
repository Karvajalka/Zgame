#include <vector>
#include <string>
#include "SDL.h"
#include "SDL_ttf.h"
#include "gui.h"
#include "SDL_print.h"
#include "SDL_init.h"

const int messageViewHeight = 20;
const int messageViewLength = 40;
const int messageXdelta = 24;

extern int xSize;
extern int ySize;

SDL_Rect viewRect = newRectangle( 0, 0, 20, 20 );
SDL_Rect messageRect = newRectangle( 24, 0, 40, 20 );

extern SDL_Surface *screen;
extern TTF_Font *font;


GuiArea chatBox( 20, 0, 40, 20 );

std::vector< std::string > messageView;

void initializeGui()
{
	fillRect( viewRect, 200, 200, 200 );
	messageView.resize( messageViewHeight );
	messageView.clear();
	chatBox.baseColour = newColour( 100, 100, 100 );
	chatBox.fontBc = newColour( 0, 0, 0 );
	chatBox.fontFc = newColour( 255, 255, 255 );
	chatBox.space = 0;
	chatBox.quality = 2;
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
}

void printMessages()
{
	chatBox.fillColour( chatBox.baseColour );
	//fillRect( messageRect, 100, 100, 100 );
	for( int y = 0; y < messageViewHeight; y++ )
		chatBox.printText( messageView[y], 0, y );
		//writeDownAt( messageView[y], messageXdelta, y );
	SDL_Flip( screen );
}

void GuiArea::fillColour( SDL_Color colour )
{
	SDL_Rect conversion = area;
	conversion.x *= xSize;
	conversion.w *= xSize;
	conversion.y *= ySize;
	conversion.h *= ySize;
	SDL_FillRect( screen , &conversion , SDL_MapRGB( screen->format , colour.r , colour.b , colour.g ));
}

void GuiArea::printText( std::string text, int x, int y )
{
	if( space )
	{
		position.x = x * xSize + area.x * xSize;
		position.y = y * ySize + area.y * xSize;
		for( unsigned int a = 0; a < text.size(); a++ )
		{
			SDL_Surface * resulting_text;
			if( quality == 0 )
				resulting_text = TTF_RenderText_Shaded( font, (const char*)text.at(a), fontFc, fontBc );
			else if( quality == 1 )
				resulting_text = TTF_RenderText_Solid( font, (const char*)text.at(a), fontFc );
			else
				resulting_text = TTF_RenderText_Blended( font, (const char*)text.at(a), fontFc );
				
			SDL_BlitSurface( resulting_text , NULL , screen , &position );
			SDL_FreeSurface( resulting_text );
			
			position.x += xSize;
		}
	}
	else
	{
		position.x = x * xSize + area.x * xSize;
		position.y = y * ySize + area.y * ySize;
		
		SDL_Surface * resulting_text;
		if( quality == 0 )
			resulting_text = TTF_RenderText_Shaded( font, text.c_str(), fontFc, fontBc );
		else if( quality == 1 )
			resulting_text = TTF_RenderText_Solid( font, text.c_str(), fontFc );
		else
			resulting_text = TTF_RenderText_Blended( font, text.c_str(), fontFc );
			
		SDL_BlitSurface( resulting_text , NULL , screen , &position );
		SDL_FreeSurface( resulting_text );
	}
}


