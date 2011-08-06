CC = g++
CCFLAGS = -g -O2
CLIENTO = SDL_init.o SDL_print.o read_configs.o main.o input.o network.o gui.o messages.o map.o
CCSFLAGS = `sdl-config --cflags --libs`

all: $(CLIENTO) client

input.o: input.cpp input.h
	$(CC) -c input.cpp $(CCSFLAGS)

SDL_init.o: SDL_init.cpp SDL_init.h
	$(CC) -c SDL_init.cpp $(CCSFLAGS)
 
SDL_print.o: SDL_print.cpp SDL_print.h
	$(CC) -c SDL_print.cpp $(CCSFLAGS)
	
gui.o: gui.cpp gui.h SDL_print.h
	$(CC) -c gui.cpp `sdl-config --cflags --libs` -lSDL_ttf 

main.o: main.cpp main.h network.h SDL_init.h read_configs.h input.h
	$(CC) -c main.cpp `sdl-config --cflags --libs`

map.o: map.h map.cpp SDL_print.h
	$(CC) -c map.cpp $(CCSFLAGS)

network.o: network.cpp network.h SDL_print.h
	$(CC) -c network.cpp `sdl-config --cflags --libs` -lSDL_net 
	
client:
	$(CC) $(CLIENTO) -o zclient `sdl-config --cflags --libs` -lSDL_ttf -lSDL_net

%.o : %.c
	$(CC) $(CCFLAGS) –c $(.SOURCE) $(CCSFLAGS)
	
clean: 
	rm -f $(CLIENTO)
