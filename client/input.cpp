#include <iostream>
#include "SDL.h"
#include "input.h"

void inputModule::getInput()
{
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
						gotInput = true;
						return;
					}
				}
				else  //if he is, he continues typing unless he presses enter, which sends the message
				{
					if( event.key.keysym.sym != SDLK_RETURN )
						inputBuffer.push_back ( ch );
					else
					{
						typing = false;
						gotInput = true;
						return;
					}
				}
			}
		}
		else if( event.type == SDL_QUIT ) // if players presses the x in the upper corner, the program quits
		{
			gotInput = true;
			inputBuffer = "/quit";
			return;
		}
	}
}

std::string inputModule::getString()  // gets a text input
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
			{
				gotInput = true;
				inputBuffer = "/quit";
				return "/quit";
			}
		}
	}
}

std::string inputModule::getChar() // gets an input of one char
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
			{
				gotInput = true;
				inputBuffer = "/quit";
				return " ";
			}
		}
	}
}

std::string inputModule::checkForBind( std::string key )
{
	/* 
	 * Checks if string key exists in the binds map. Return empty string
	 * if it doesn't exist
	 */
	std::map< std::string,std::string>::iterator it;
	it = binds.find( key );
	if( it != binds.end() )
		return (*it).second;
	else
		return "";
}


void inputModule::addBind( std::string key, std::string word )
{
	/*
	 * It checks if the word has allready been binded to something, 
	 * if it hasn't, it just adds a new pair to the aliases. If it does
	 * exist, it first deletes the old one and adds a new one after that
	 */
	std::map< std::string,std::string>::iterator it;
	it = binds.find( key );
	
	if( it != binds.end() ) 
		binds[key] = word;
	else
	{
		binds.erase(it);
		binds[key] = word;
	}
}
