#include <vector>
#include <string>
#include "SDL.h"
#include "SDL_ttf.h"
#include "gui.h"
#include "messages.h"
#include "SDL_print.h"
#include "SDL_init.h"
#include "map.h"

extern int xSize;
extern int ySize;

/*
extern const int messageViewHeight;
extern const int messageViewLength;
extern const int messageXdelta;
extern std::vector< std::string > messageView;
*/

SDL_Rect viewRect = newRectangle( 0, 0, 21, 21 );
SDL_Rect messageRect = newRectangle( 24, 0, 40, 20 );

extern SDL_Surface *screen;
extern TTF_Font *font;


void renderView()
{
	fillRect( viewRect, 0, 0, 0 );
	printMap();
	SDL_Flip(screen);
}
/*
GuiArea chatBox( 20, 0, 40, 20 );

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
*/

