compile: 

game.o: game.c game.h
	@gcc -c game.c 
server.o: server.c game.h networking.h
	@gcc -c server.c 
client.o: client.c game.h networking.h
	@gcc -c client.c
networking.o: networking.c
	@gcc -c networking.c 
testing.o: testing.c game.h
	@gcc -c testing.c 
tests: game.o testing.o
	@gcc -o tests testing.o game.o
test: tests
	@./tests

clean:
	@rm -f *.o tests

