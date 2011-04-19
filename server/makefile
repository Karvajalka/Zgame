SCFLAGS = `sdl-config --cflags --libs` -lSDL_net 
SERVERO = main.o network.o network_init.o client.o string_ext.o convert.o world.o 

all: $(SERVERO) zserver

network_init.o: network_init.cpp network_init.h
	g++ -c network_init.cpp $(SCFLAGS)

network.o: network.cpp network.h client.h
	g++ -c network.cpp $(SCFLAGS)

client.o: client.cpp client.h string_ext.h network.h convert.h
	g++ -c client.cpp `sdl-config --cflags --libs` -lSDL_net 

string_ext.o: string_ext.cpp string_ext.h
	g++ -c string_ext.cpp 

%.o : %.c
	g++ $(SCFLAGS) –c $(.SOURCE) 
	
zserver:
	g++ $(SERVERO) -o zserver `sdl-config --cflags --libs` -lSDL_net 

clean: 
	rm zserver $(SERVERO)