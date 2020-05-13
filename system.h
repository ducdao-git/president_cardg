#ifndef SYSTEM_SEEN
#define SYSTEM_SEEN

#include "player.h"
#include "input.h"

/*
 * Purpose: The card game itself. The function call upon players action and process the card. It will move the card from a player hand to the discard pile. The function will stop once a player have no card left.

 * Parameters:
      player_list - list of player where each element is a player
      player_num - number of player in the current game
      pile - the discard pile use to keep track played card
*/
void game_play(struct player *player_list, unsigned int player_num,
               struct discard *pile);

/*
 * Purpose: Processing the input card. The function scan in a player's input card and then compare it with the previous played card(s) and see if this player have these cards. If all satisfy, it then remove that card from the current player hand.

 * Parameters:
      player - player that will go in this turn
      player_name - name of player that will go in this turn
      point_sum - sum of all card point from previous played card
      played_card_num - number of card that played in previous non-passing turn
      point - array of card point of input card
*/
void card_process(struct player *player, unsigned int player_name,
                  unsigned int point_sum, unsigned int played_card_num, unsigned int *point);

/*
 * Purpose: Menu, ask if player need to read game rule or user documentation before starting the game
*/
void welcome();
#endif
