#include <iostream>
#include "SDL.h"
#include "SDL_ttf.h"

#include "SDL_init.h"

TTF_Font *font = NULL;
SDL_Surface *screen = NULL;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;

int fontsize = 20;
int xSize = fontsize - 4;
int ySize = fontsize + 4;

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

