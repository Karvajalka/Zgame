#include <string>
#include <iostream>
#include "SDL.h"
#include "input.h"
#include "network.h"

SDL_Event event;

extern bool running;
extern bool loadFont();

void getInput()
{
        static std::string inputBuffer;
        static bool typing;
        if( SDL_PollEvent( &event ) )  //key pressed?
        {
                if( event.type == SDL_KEYDOWN )
                {
			unsigned char ch;				
			if( event.key.keysym.unicode < 0x80 && event.key.keysym.unicode > 0 )
			{
				ch = (unsigned char)event.key.keysym.unicode;
				if( !typing ) //is player typing?
				{
					if( event.key.keysym.sym == SDLK_RETURN ) //player pressed the "say" key, instead of single keypress, it takes a line of text
						typing = true;
					else //otherwise just figures what action is bound to the key
					{
						inputBuffer.push_back( ch );
						processInput( inputBuffer );
						inputBuffer.clear();
					}
				}
				else  //if he is, he continues typing unless he presses enter, which sends the message
				{
					if( event.key.keysym.sym != SDLK_RETURN )
						inputBuffer.push_back ( ch );
					else
					{
						typing = false;
						processInput( inputBuffer );
						inputBuffer.clear();
					}
				}
			}
		}
		else if( event.type == SDL_QUIT ) // if players presses the x in the upper corner, the program quits
			running = false;   
		}
}

void processInput( std::string input )
{
	std::cout << input << std::endl;
	sendServer( input + "\n" );
}

std::string getString()  // gets a text input
{
	std::string sString;
	sString.clear();
	while( true )
	{
		if( SDL_PollEvent( &event ) )
		{
			if( event.type == SDL_KEYDOWN )
			{
				unsigned char ch;				
				if( event.key.keysym.unicode < 0x80 && event.key.keysym.unicode > 0 )					
				{
					ch = (unsigned char)event.key.keysym.unicode;
					if( event.key.keysym.sym == SDLK_RETURN )
						return sString;
					else
					        sString.push_back( ch );
				}
			}
			else if( event.type == SDL_QUIT )
				running = false;
		}
	}
}

std::string getChar() // gets an input of one char
{
	std::string sChar;
        sChar.clear();
        while( true )
        {
	        if( SDL_PollEvent( &event ) )
	        {
	        	if( event.type == SDL_KEYDOWN )
		        {
			        unsigned char ch;				
		        	if( event.key.keysym.unicode < 0x80 && event.key.keysym.unicode > 0 )				
		        	{
		        		ch = (unsigned char)event.key.keysym.unicode;
		        		sChar.push_back(ch);
		        		return sChar;
		        	}
		        }
	        	else if( event.type == SDL_QUIT )
	        		running = false;
	        }
        }
}

