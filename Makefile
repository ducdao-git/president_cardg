CFLAGS=-std=c99 -Wall
CC=gcc

card_game: input.o cards.o player.o system.o main.o
	$(CC) $(CFLAGS) input.o cards.o player.o system.o main.o -o card_game

main.o: macro_lib.h input.h cards.h player.h system.h main.c
	$(CC) $(CFLAGS) -c main.c

system.o: macro_lib.h input.h cards.h player.h system.h system.c
	$(CC) $(CFLAGS) -c system.c

player.o: macro_lib.h cards.h player.h player.c
	$(CC) $(CFLAGS) -c player.c

cards.o: macro_lib.h cards.h cards.c
	$(CC) $(CFLAGS) -c cards.c

input.o: macro_lib.h input.h input.c
	$(CC) $(CFLAGS) -c input.c

clean:
	rm -f card_game *.o
	clear
