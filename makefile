CLIDIR = client
SERDIR = server

wclient: client/read_configs.o
	@cd $(CLIDIR) ; make all
	@cp client/zclient.exe zclient.exe
	
wserver: server/world.o
	@cd $(SERDIR) ; make all
	@cp server/zserver.exe zserver.exe

wall:
	make wclient
	make wserver

lclient: client/read_configs.o
	@cd $(CLIDIR) ; make all
	@cp client/zclient zclient
	
lserver: server/world.o
	@cd $(SERDIR) ; make all
	@cp server/zserver zserver

lall:
	make lclient
	make lserver

	
clean: 
	make cser
	make cli
	
cser:
	@cd $(SERDIR) ; make clean
	
cli:
	@cd $(CLIDIR) ; make clean
