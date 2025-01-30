CC = gcc 
CFLAGS = -Wall -ansi -pedantic -g -DDEBUG
CLIB = -lscreen -L.

all: anthill 

anthill: game_loop.o game.o command.o game_actions.o graphic_engine.o space.o game_reader.o
	$(CC) -o $@ $^ $(CLIB)

#######################################################
game_loop.o: game_loop.c command.h game.h game_actions.h graphic_engine.h types.h space.h game_reader.h
	$(CC) $(CFLAGS) -c $<

command.o: command.c command.h  types.h
	$(CC) $(CFLAGS) -c $<

game_actions.o:  game_actions.c game_actions.h command.h game.h types.h
	$(CC) $(CFLAGS) -c $<

game_reader.o: game_reader.c game_reader.h game.h types.h command.h space.h
	$(CC) $(CFLAGS) -c $<

graphic_engine.o: graphic_engine.c graphic_engine.h command.h space.h types.h libscreen.h game.h
	$(CC) $(CFLAGS) -c $<

game.o: game.c game.h command.h space.h types.h game_reader.h
	$(CC) $(CFLAGS) -c $<

space.o: space.c space.h types.h
	$(CC) $(CFLAGS) -c $<

###############################
clean:
	@echo "Cleaning all..."
	rm *.o -f anthill