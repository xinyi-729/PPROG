CC = gcc 
CFLAGS = -Wall -pedantic -g -DDEBUG
CLIB = -lscreen -L.

##hay q volverle a añadir el -ansi, lo quité para usar //

all: anthill 

anthill: game_loop.o game.o command.o game_actions.o graphic_engine.o space.o game_reader.o player.o object.o set.o character.o inventory.o link.o
	$(CC) -o $@ $^ $(CLIB)

###################TESTS############################

test_space: space_test.o space.o set.o
	$(CC) -o $@ $^ $(CLIB)

test_set: set_test.o set.o
	$(CC) -o $@ $^ $(CLIB)

test_character: character_test.o character.o
	$(CC) -o $@ $^ $(CLIB)

#######################################################
command.o: command.c command.h types.h
	$(CC) $(CFLAGS) -c $<

game_actions.o:  game_actions.c game_actions.h command.h types.h game.h space.h set.h object.h player.h inventory.h character.h
	$(CC) $(CFLAGS) -c $<	

game_loop.o: game_loop.c command.h types.h game.h space.h set.h object.h player.h inventory.h character.h game_actions.h graphic_engine.h game_reader.h link.h
	$(CC) $(CFLAGS) -c $<

game_reader.o: game_reader.c game_reader.h types.h game.h command.h space.h set.h object.h player.h inventory.h character.h link.h
	$(CC) $(CFLAGS) -c $<

game.o: game.c game_reader.h types.h game.h command.h space.h set.h object.h player.h inventory.h character.h link.h
	$(CC) $(CFLAGS) -c $<

graphic_engine.o:  graphic_engine.c graphic_engine.h game.h command.h types.h space.h set.h object.h player.h inventory.h character.h libscreen.h
	$(CC) $(CFLAGS) -c $<
	
object.o: object.c object.h types.h 
	$(CC) $(CFLAGS) -c $<

player.o: player.c player.h types.h inventory.h set.h
	$(CC) $(CFLAGS) -c $<

space.o: space.c space.h types.h set.h
	$(CC) $(CFLAGS) -c $<

set.o: set.c set.h types.h
	$(CC) $(CFLAGS) -c $<

character.o: character.c character.h types.h
	$(CC) $(CFLAGS) -c $<

link.o: link.c link.h types.h
	$(CC) $(CFLAGS) -c $<

inventory.o: inventory.c inventory.h set.h types.h
	$(CC) $(CFLAGS) -c $<
	
####################TESTS######################
space_test.o: space_test.c space_test.h space.h test.h
	$(CC) $(CFLAGS) -c $<

set_test.o: set_test.c set_test.h set.h
	$(CC) $(CFLAGS) -c $<

character_test.o: character_test.c character_test.h character.h
	$(CC) $(CFLAGS) -c $<

###############################
clean:
	@echo "Cleaning all..."
	rm *.o -f anthill
	rm -f test_set test_space test_character
	
