CC = g++
CFLAGS = -std=c++0x
SCFLAGS = `sdl-config --cflags --libs` -lSDL_net 
SERVERO = main.o network.o network_init.o client.o string_ext.o convert.o world.o dvector.o

all: $(SERVERO) zserver

network_init.o: network_init.cpp network_init.h
	$(CC) -c network_init.cpp $(SCFLAGS)

network.o: network.cpp network.h client.h
	$(CC) -c network.cpp $(SCFLAGS)

client.o: client.cpp client.h string_ext.h network.h convert.h
	$(CC) -c client.cpp $(SCFLAGS)
	
main.o: main.cpp main.h network.h network_init.h
	$(CC) -c main.cpp $(SCFLAGS)

%.o : %.c
	$(CC)  –c $(.SOURCE) $(SCFLAGS)
	
zserver: $(SERVERO)
	$(CC)  $(SERVERO) -o zserver $(SCFLAGS)

clean: 
	rm -f $(SERVERO)