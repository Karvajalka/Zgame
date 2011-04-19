#include <string>
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_print.h"

extern TTF_Font *font;
extern SDL_Surface *screen;

extern int fontsize;
extern int xSize;
extern int ySize;
extern SDL_Color fontbgcolor;
extern SDL_Color fontcolor;
bool space;

SDL_Rect defPos;

void writeDownAt( std::string text, int x, int y )
{
	if( space )
	{
		SDL_Rect rN;
		rN.x = x * xSize;
		rN.y = y * ySize;
		for( unsigned int x = 0; x < text.size(); x++ )
		{
			SDL_Surface * resulting_text = TTF_RenderText_Shaded( font, (const char*)text.at(x), fontcolor, fontbgcolor );
			SDL_BlitSurface( resulting_text , NULL , screen , &rN );
			rN.x += xSize;
			SDL_FreeSurface( resulting_text );
		}
	}
	else
	{
		defPos.x = x * ( fontsize - 4 );
		defPos.y = y * ( fontsize + 4 );
		SDL_Surface * resulting_text = TTF_RenderText_Shaded( font, text.c_str(), fontcolor, fontbgcolor );
		SDL_BlitSurface( resulting_text , NULL , screen , &defPos );
		SDL_FreeSurface( resulting_text );
	}
}

