#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <vector>
#include <string>

#include "SDL.h"
#include "SDL_ttf.h"

#include "messages.h"
#include "map.h"

class graphicsModule
{
	public:
		SDL_Surface *screen;
		TTF_Font *font;
		int SCREEN_WIDTH;
		int SCREEN_HEIGHT;
		int SCREEN_BPP;
		
		bool space;
		SDL_Rect defPos;
		
		Map defaultView;
		
		SDL_Colour frColour, bgColour;  // front and background colours
		std::vector< SDL_Colour* > colours;  // list of all loaded colours
		
		int fontsize; // SCREEN_WIDTH/70
		int borderSize; // if you print a single char, this determines the amount of space around it. If this is 0 it looks quite bad
		int xSize;
		int ySize;
		SDL_Rect viewRect;
		
		chatClass * chat;
		void updateChat();
		
		bool init_SDL();
		bool loadFont();
		void close_SDL();
		
		void fillRect( SDL_Rect rectangle, int r, int b, int g );
		void writeDownAt( std::string text, int x, int y );
		void update();
		void printMap();
		void rotate( Map* map );
		
		
		SDL_Rect newRectangle( int x, int y, int w, int h );
		SDL_Color newColour( int r, int b, int g );
		
		graphicsModule()
		{
			SCREEN_WIDTH = 800;
			SCREEN_HEIGHT = 480;
			SCREEN_BPP = 32;

			bgColour = newColour( 0,0,0 );
			frColour = newColour( 255,255,255 );
			chat = new chatClass();
			fontsize = 16; // SCREEN_WIDTH/70
			borderSize = 4; // if you print a single char, this determines the amount of space around it. If this is 0 it looks quite bad
			xSize = fontsize - borderSize;
			ySize = fontsize + borderSize;
			viewRect = newRectangle( 0, 0, 21, 21 );
			space = true;
		}
};



#endif
