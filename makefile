CLIDIR = client
SERDIR = server

wclient: 
	@cd $(CLIDIR) ; make all
	@cp client/zclient.exe testfolder/zclient.exe
	
wserver: 
	@cd $(SERDIR) ; make all
	@cp server/zserver.exe testfolder/zserver.exe

wall:
	make wclient
	make wserver

lclient: 
	@cd $(CLIDIR) ; make all
	@cp client/zclient zclient
	
lserver:
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
