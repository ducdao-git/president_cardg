#ifndef PLAYER_SEEN
#define PLAYER_SEEN

#include "cards.h"


/*
 * Purpose: create player by assign value to number of card and an array of card to a player.

 * Parameters:
      deck - the array conain 52 cards that have already been suffle
      player_list - list of player where each element represent a player
      player_num - number of player in the current game
*/
void create_player(struct card *deck, struct player *player_list,
                   unsigned int player_num);

/*
 * Purpose: create player cards by allocate an array in the heap and store the card value on each element. Then sort cards in decending order.

 * Parameters:
      deck - the array conain 52 cards that have already been suffle
      cards_num - number of card each player should have
      player_count - index of the player in player list

 * Return Value:
      . return the pointer the heap array
*/
struct card *player_cards(struct card *deck, unsigned int cards_num,
                          unsigned int player_count);

/*
 * Purpose: print out all the card that currently hold by a player.

 * Parameters:
      player - the player want their card to be print out
      player_name - index of the player in player list + 1
*/
void print_player_cards(struct player *player, unsigned int player_name);

#endif
