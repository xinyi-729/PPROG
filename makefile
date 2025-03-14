CC = gcc 
CFLAGS = -Wall  -pedantic -g -DDEBUG
CLIB = -lscreen -L.

all: anthill 

anthill: game_loop.o game.o command.o game_actions.o graphic_engine.o space.o game_reader.o player.o object.o set.o
	$(CC) -o $@ $^ $(CLIB)

test: space_test.o space.o set.o
	$(CC) -o $@ $^ $(CLIB)

#######################################################
command.o: command.c command.h types.h
	$(CC) $(CFLAGS) -c $<

game_actions.o:  game_actions.c game_actions.h command.h game.h types.h player.h space.h
	$(CC) $(CFLAGS) -c $<	

game_loop.o: game_loop.c command.h game.h game_actions.h graphic_engine.h space.h game_reader.h
	$(CC) $(CFLAGS) -c $<

game_reader.o: game_reader.c game_reader.h game.h types.h
	$(CC) $(CFLAGS) -c $<

game.o: game.c game.h command.h space.h types.h player.h object.h
	$(CC) $(CFLAGS) -c $<

graphic_engine.o: graphic_engine.c graphic_engine.h  command.h libscreen.h space.h types.h game.h
	$(CC) $(CFLAGS) -c $<
	
object.o: object.c object.h types.h 
	$(CC) $(CFLAGS) -c $<

player.o: player.c player.h types.h
	$(CC) $(CFLAGS) -c $<

space.o: space.c space.h types.h set.h
	$(CC) $(CFLAGS) -c $<

set.o: set.c set.h types.h
	$(CC) $(CFLAGS) -c $<

##########################################
space_test.o: space_test.c space_test.h space.h test.h
	$(CC) $(CFLAGS) -c $<


###############################
clean:
	@echo "Cleaning all..."
	rm *.o -f anthill
