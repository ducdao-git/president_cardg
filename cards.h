#ifndef CARD_SEEN
#define CARD_SEEN

#include "macro_lib.h"

/*
 * Purpose: create a deck of cards by assign value to each element of array size 52 type struct card in array which represent 52 cards in a a deck. And call on print card to print out the the initiall deck. Then suffle the deck.

 * Parameters:
      deck - the array where card value will be store and then suffle up
*/
void initialize_deck(struct card *deck);

/*
 * Purpose: print out a card base on the card rank and suit.

 * Parameters:
      card - a card to be print
*/
void print_card(struct card card);

/*
 ! point is an unique value of a card and be store within a variable in struct card. It can be calculate with point = rank * 4 + suit.

 * Purpose: Convert a card point to card. The function calculate card rank and suit base on it point.

 * Parameters:
      card - an empty card. (empty card - a variable not have value)
      point - the card that need to convert back to card
*/
void point_to_card(struct card *card, unsigned int point);

/*
 * Purpose: swap place of 2 cards by swapping their value.

 * Parameters:
      card_1 - the card will be swap with the second card
      card_2 - the card will be swap with the first card
*/
void swap_card(struct card *card_1, struct card *card_2);

/*
 * Purpose: suffle card by randomly put every element of the array to a new location within the array.

 * Parameters:
      deck - the array previously initialize as array of 52 card
*/
void suffle_cards(struct card *deck);

/*
 * Purpose: short card in order largest to smalest. Using the sell sort   algorithm (with gap = n/2 n/4 n/8 ...), it short all the element in the array base on element point (the card point).

 * Parameters:
      card_list - the array where it element will be sort
      cards_num - number of element in card_list array
*/
void shellSort_cards(struct card *card_list, int cards_num);

/*
 * Purpose: delete cards in a player card list by shifting all the card at the right of the deleted card to left 1 index.

 * Parameters:
      player - the player where their card list will be delete
      point - array of card point of card to be delete
*/
void delete_card(struct player *player, unsigned int *point);

/*
 * Purpose: check if card(s) belong to a player. By call on card_index function, it can see if player cards array have an element with the input card point value.

 * Parameters:
      player - the player where their card list will be check
      point - array of card point of card to be check

 * Return Value:
      . return 0 if player doesn't have the card
      . return 1 if player has the card
*/
int is_player_card(struct player *player, unsigned int *point);

/*
 * Purpose: find index of a card in player cards list. Using interpolation seach algorithm to find index of the element in the player card array that have the same point value with the point of the searching card.

 * Parameters:
      player - the player where their card list will be search
      point - array of card point of card to be search

 * Return Value:
      . return -1 if player doesn't have the card
      . return the card index if player has the card
*/
int card_index(struct player *player, unsigned int point);

/*
 ! the discard pile is store in order last played - last index, so we print the card from the end rather from beginning

 * Purpose: print out the previous played cards. (only print (player_num - 1) card from discard pile)

 * Parameters:
      player_num - the number of player in the current game
      turn_count - the number of turn in the current round
      pile - the discard pile where it element store card point of played card
      player_list - list of player to get data on each player
*/
void print_discard_pile(unsigned int player_num, unsigned int turn_count,
                        struct discard *pile, struct player *player_list);

#endif
