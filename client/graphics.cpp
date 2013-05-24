#include <iostream>
#include <math.h>
#include "graphics.h"
#include "map.h"


bool graphicsModule::init_SDL()
{
	/*
	 * Initializes SDL, sets up the screen and the caption. Initializes
	 * SDL_ttf and calls the function to load the basic font
	 */
	if( SDL_Init( SDL_INIT_NOPARACHUTE ) == -1 ) //init SDL
		return false;
	
	screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
	
	if( screen == NULL ) //init screen
		return false;    

	if (TTF_Init( ) == -1) //init TTF
		return false;

	SDL_WM_SetCaption( "Zclient", NULL ); //set the window caption

	if( !loadFont() ) // load the font
		return false;

	SDL_EnableUNICODE(1);   
	return true;
} 

bool graphicsModule::loadFont()
{
   font = TTF_OpenFont( "font.ttf", fontsize );
   
   if ( font == NULL )
   {
      std::cout << "	-Can't load the damned font" << std::endl;
      return false;
   }
   
   std::cout << "	-Font loaded" << std::endl;
   return true;
}

void graphicsModule::update()
{
	fillRect( viewRect, 0, 0, 0 );
	printMap();
	SDL_Flip( screen );
}

void graphicsModule::close_SDL()
{
   SDL_FreeSurface( screen );
   SDL_Quit();    
   TTF_Quit();
}

SDL_Rect graphicsModule::newRectangle( int x, int y, int w, int h ) // wanted an easy way to get rectangles
{
	SDL_Rect a; 
	a.x = x; 
	a.y = y; 
	a.h = h; 
	a.w = w;
	return a;
}

SDL_Color graphicsModule::newColour( int r, int b, int g )
{
	SDL_Color a;
	a.r = r;
	a.b = b;
	a.g = g;
	return a;
}

void graphicsModule::fillRect( SDL_Rect rectangle, int r, int b, int g )
{
	rectangle.x*=xSize;
	rectangle.y*=ySize;
	rectangle.w*=xSize;
	rectangle.h*=ySize;
	SDL_FillRect( screen , &rectangle , SDL_MapRGB(screen->format , r , b , g) );
}

void graphicsModule::writeDownAt( std::string text, int x, int y )  //writes text at position x,y in the defautl screen
{
	SDL_Rect rN;
	rN.x = x * xSize;
	rN.y = y * ySize;
	if( space )
	{
		for( unsigned int a = 0; a < text.size(); a++ )
		{
			SDL_Surface * resulting_text = TTF_RenderText_Shaded( font, &text[a] , frColour, bgColour );
			SDL_BlitSurface( resulting_text , NULL , screen , &rN );
			rN.x += xSize;
			SDL_FreeSurface( resulting_text );
		}
	}
	else
	{
		SDL_Surface * resulting_text = TTF_RenderText_Shaded( font, text.c_str(), frColour, bgColour );
		SDL_BlitSurface( resulting_text , NULL , screen , &rN );
		SDL_FreeSurface( resulting_text );
	}
}

void graphicsModule::printMap()
{
	int viewSize = defaultView.viewSize;
	for( int x = 0; x < viewSize; x++ )
	{
		for( int y = 0; y < viewSize; y++ )
		{
			std::string temp;
			temp.push_back( defaultView.mapArray[x][y] );

			writeDownAt( temp,  x,  y );
		}
	}
}

void graphicsModule::updateChat( )
{
	for( int i = 0; i < chat->height; i++ )
		writeDownAt( chat->chatText[ (chat->newest + i)%chat->height ], 20, i );
	
	SDL_Flip( screen );
}

void graphicsModule::rotate( Map* map )
{
	Map newView = *map;
	for( int xp = 0; xp < map->viewSize; xp++ )
		for( int yp = 0; yp < map->viewSize; yp++ )
		{
			int temp = map->rotation;
			int offset = ( map->viewSize - 1 )/2;
			int x = xp - offset;
			int y = yp - offset;
			
			if( abs(x) < abs(y) )
				temp *= abs(y);
			else
				temp *= abs(x);
				
			while( temp > 0 )
			{
				temp--;
				if( abs(x) < abs(y) )
				{
					if ( y > 0 )
						x++;
					else
						x--;
				}
				else
				{
					if( abs(x) != abs(y) )
					{
						if( x > 0 )
							y--;
						else
							y++;
					}
					else
					{
						if( x > 0 && y > 0 )
							y--;
						else if( x > 0 && y < 0 )
							x--;
						else if( x < 0 && y < 0 )
							y++;
						else if( x < 0 && y > 0 )
							x++;
					}
				}
			}
			map->mapArray[ x + offset ][ y + offset ] = newView.mapArray[xp][yp];
		}
}
	
	



