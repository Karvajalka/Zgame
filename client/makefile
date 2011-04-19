CCFLAGS = -g -O2

CLIENTO = SDL_init.o SDL_print.o read_configs.o main.o input.o network.o network_init.o

all: $(CLIENTO) client

input.o: input.cpp input.h
	g++ -c input.cpp `sdl-config --cflags --libs`

SDL_init.o: SDL_init.cpp SDL_init.h
	g++ -c SDL_init.cpp `sdl-config --cflags --libs`
 
SDL_print.o: SDL_print.cpp SDL_print.h
	g++ -c SDL_print.cpp `sdl-config --cflags --libs`

main.o: main.cpp main.h network.h network_init.h SDL_init.h read_configs.h input.h
	g++ -c main.cpp `sdl-config --cflags --libs`

network_init.o: network_init.cpp network_init.h
	g++ -c network_init.cpp `sdl-config --cflags --libs` -lSDL_net 

network.o: network.cpp network.h
	g++ -c network.cpp `sdl-config --cflags --libs` -lSDL_net 
	
client:
	g++ $(CLIENTO) -o zclient `sdl-config --cflags --libs` -lSDL_ttf -lSDL_net

%.o : %.c
	g++ $(CCFLAGS) –c $(.SOURCE) 
	
clean: 
	rm zclient.exe zclient $(CLIENTO)
