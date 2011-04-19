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
        if( SDL_PollEvent( &event ) )
        {
                if( event.type == SDL_KEYDOWN )
                {
			unsigned char ch;				
			if( event.key.keysym.unicode < 0x80 && event.key.keysym.unicode > 0 )	
			{
				ch = (unsigned char)event.key.keysym.unicode;
				if( !typing )
				{
					if( event.key.keysym.sym == SDLK_RETURN )
						typing = true;
					else
					{
						inputBuffer.push_back( ch );
						processInput( inputBuffer );
						inputBuffer.clear();
					}
				}
				else
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
	else if( event.type == SDL_QUIT )
		running = false;   
        }
}

void processInput( std::string input )
{
        std::cout << input << std::endl;
	sendServer( input + "\n" );
}

std::string getString()
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

std::string getChar()
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

