#ifndef INPUT_H
#define INPUT_H
#include <string>
#include <map>

class inputModule
{
	public:
		bool gotInput;
		bool typing;
		SDL_Event event;
		std::string inputBuffer;
		
		std::map< std::string,std::string> binds;
		
		
		void addBind( std::string key, std::string word );
		std::string checkForBind( std::string key );
		
		void getInput();
		std::string getChar();
		std::string getString();
		inputModule()
		{
			gotInput = false;
			typing = false;
		}
};

#endif
