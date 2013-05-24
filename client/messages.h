#ifndef MESSAGES_H
#define MESSAGES_H
#include <string>
#include <vector>
#include "SDL.h"
//void newMessage( std::string message );
//void printMessages();

class chatClass
{
	public:
		std::vector< std::string > chatText;
		std::vector< std::vector<int> > chatColour;
		
		int height, scroll, newest, width;
		void updateChat( std::string * s );
		
		chatClass()
		{
			height = 8;
			width = 30;
			scroll = 0;
			newest = 0;
			chatText.assign( height, "" );
		}
};

class Character
{
	public:
		char sign;
		SDL_Color colour;
		
		Character(){}
		
		Character( SDL_Color c, char s )
		{
			sign = s;
			colour = c;
		}
};

#endif
