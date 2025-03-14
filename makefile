CC = gcc 
CFLAGS = -Wall -pedantic -g -DDEBUG
CLIB = -lscreen -L.

##hay q volverle a añadir el -ansi, lo quité para usar //

all: anthill 

anthill: game_loop.o game.o command.o game_actions.o graphic_engine.o space.o game_reader.o player.o object.o set.o character.o
	$(CC) -o $@ $^ $(CLIB)

###################TESTS############################

test_space: space_test.o space.o set.o
	$(CC) -o $@ $^ $(CLIB)

test_set: set_test.o set.o
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

game.o: game.c game.h command.h space.h types.h player.h object.h character.h
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

character.o: character.c character.h types.h
	$(CC) $(CFLAGS) -c $<

####################TESTS######################
space_test.o: space_test.c space_test.h space.h test.h
	$(CC) $(CFLAGS) -c $<

set_test.o: set_test.c set_test.h set.h
	$(CC) $(CFLAGS) -c $<

###############################
clean:
	@echo "Cleaning all..."
	rm *.o -f anthill
	rm -f test_set test_space
	
