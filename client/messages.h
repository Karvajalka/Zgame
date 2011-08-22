#ifndef MESSAGES_H
#define MESSAGES_H
#include <string>
#include <vector>
#include "SDL.h"
//void newMessage( std::string message );
//void printMessages();

class MessageWindow
{
	public:
		std::vector< std::string > chatText;
		std::vector< std::vector<int> > chatColour;
		
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
