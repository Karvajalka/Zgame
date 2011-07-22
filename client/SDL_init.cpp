#include <iostream>
#include "SDL.h"
#include "SDL_ttf.h"

#include "SDL_init.h"

TTF_Font *font = NULL;
SDL_Surface *screen = NULL;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

int fontsize = 12;
int borderSize = 4; // if you print a single sign, this determines the amount of space around it
int xSize = fontsize - borderSize;
int ySize = fontsize + borderSize;

SDL_Color fontbgcolor = { 0, 0, 0 };
SDL_Color fontcolor = { 255, 255, 255 };

bool init_SDL()
{
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

bool loadFont()
{
   font = TTF_OpenFont( "font.ttf", fontsize );
   
   if ( font == NULL )
   {
      std::cout << "Can't load the damned font" << std::endl;
      return false;
   }
   
   std::cout << "font loaded" << std::endl;
   return true;
}

void close_SDL()
{
   SDL_FreeSurface( screen );
   SDL_Quit();    
   TTF_Quit();
}

SDL_Rect newRectangle( int x, int y, int w, int h ) // wanted an easy way to get rectangles
{
	SDL_Rect a; 
	a.x = x; 
	a.y = y; 
	a.h = h; 
	a.w = w;
	return a;
}

SDL_Color newColour( int r, int b, int g )
{
	SDL_Color a;
	a.r = r;
	a.b = b;
	a.g = g;
	return a;
}
