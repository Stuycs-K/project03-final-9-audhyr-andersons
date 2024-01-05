compile: 

game.o: game.c game.h
	@gcc -c game.c game.h
server.o: server.c game.h networking.h
	@gcc -c server.c 
client.o: client.c game.h networking.h
	@gcc -c client.c
networking.o: networking.c
	@gcc -c networking.c 

