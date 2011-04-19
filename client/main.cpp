#include <iostream>

#if defined(WIN32)

#include <windows.h>

#endif

#include "SDL.h"
#include "main.h"
#include "SDL_init.h"
#include "SDL_print.h"
#include "network_init.h"
#include "read_configs.h"
#include "network.h"
#include "input.h"

extern SDL_Surface *screen;

const int DELAY_AMOUNT = 20;
bool running = 1;
#if defined(WIN32)
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR
lpCmdLine, int nCmdShow )
#else
int main()
#endif
{
	if( !init_SDL() )
		return 0;
	if( initConnection() == -1 )
	{
		std::cout << "failed to establish connection" << std::endl;
		return 0;
	}
   //if( read_configs )
      //return 0;
	while( running ) //main loop
	{
		checkRecieve();
		getInput();
		SDL_Delay( DELAY_AMOUNT );
	}
	close_SDL();
	return 1;
}
