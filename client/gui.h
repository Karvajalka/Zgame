#ifndef GUI_H
#define GUI_H
#include <string>
#include <SDL.h>

void initializeGui();
void newMessage( std::string message );
void printMessages();

class GuiArea
{
	public:
		bool space;
		int quality;
		SDL_Rect area;			//the area
		SDL_Rect position;			//position
		SDL_Color fontBc;   	//font colour
		SDL_Color fontFc;		//font bg colour
		SDL_Color baseColour;	//base colour for the whole area
		void fillColour( SDL_Color colour );
		void printText( std::string text, int x, int y );
		void printOffsetText( std::string text, int x, int y, int xOff, int yOff );
		GuiArea( int x, int y, int w, int h )
		{
			area.x = x;
			area.y = y;
			area.w = w;
			area.h = h;
		}
};

#endif