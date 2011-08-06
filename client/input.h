#ifndef INPUT_H
#define INPUT_H
#include <string>

class inputModule
{
	public:
		bool gotInput;
		bool typing;
		SDL_Event event;
		std::string inputBuffer;
		
		void getInput();
		std::string getChar();
		std::string getString();
};
#endif
