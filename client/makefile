CC = g++
CCFLAGS = -g -O2
CLIENTO = graphics.o read_configs.o main.o input.o network.o messages.o map.o stringExt.o
CCSFLAGS = `sdl-config --cflags --libs` 

all: $(CLIENTO) client

input.o: input.cpp input.h
	$(CC) -c input.cpp $(CCSFLAGS)

read_configs.o: read_configs.cpp read_configs.h
	$(CC) -c read_configs.cpp $(CCSFLAGS) -lSDL_net

graphics.o: graphics.cpp graphics.h
	$(CC) -c graphics.cpp $(CCSFLAGS) -lSDL_ttf

main.o: main.cpp main.h network.h read_configs.h input.h
	$(CC) -c main.cpp $(CCSFLAGS)

map.o: map.h map.cpp 
	$(CC) -c map.cpp $(CCSFLAGS)
	
messages.o: messages.h messages.cpp 
	$(CC) -c messages.cpp $(CCSFLAGS)

network.o: network.cpp network.h
	$(CC) -c network.cpp $(CCSFLAGS) -lSDL_net 
	
client:
	$(CC) $(CLIENTO) -o zclient $(CCSFLAGS) -lSDL_ttf -lSDL_net

%.o : %.c
	$(CC) $(CCFLAGS) –c $(.SOURCE) $(CCSFLAGS)
	
clean: 
	rm -f $(CLIENTO)
