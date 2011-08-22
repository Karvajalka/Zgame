CC = g++
CFLAGS = -std=c++0x
SCFLAGS = `sdl-config --cflags --libs` -lSDL_net 
SERVERO = main.o network.o client.o string_ext.o convert.o world.o dvector.o subnetwork.o clientmodule.o

all: $(SERVERO) zserver

network.o: network.cpp network.h 
	$(CC) -c network.cpp $(SCFLAGS)
	
subnetwork.o: subnetwork.cpp subnetwork.h 
	$(CC) -c subnetwork.cpp $(SCFLAGS)

client.o: client.cpp client.h string_ext.h network.h convert.h
	$(CC) -c client.cpp $(SCFLAGS)
	
clientmodule.o: clientmodule.cpp clientmodule.h 
	$(CC) -c clientmodule.cpp $(SCFLAGS)
	
main.o: main.cpp main.h network.h
	$(CC) -c main.cpp $(SCFLAGS)

%.o : %.c
	$(CC)  –c $(.SOURCE) $(SCFLAGS)
	
zserver: $(SERVERO)
	$(CC)  $(SERVERO) -o zserver $(SCFLAGS)

clean: 
	rm -f $(SERVERO)
