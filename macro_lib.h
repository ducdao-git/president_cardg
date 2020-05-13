// all library and macro using in the program

#ifndef MACRO_LIB_SEEN
#define MACRO_LIB_SEEN

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

/*change these 4 macro to fit with your system terminal
  currently set to work with MAC OS terminal*/
#define CLEAR "clear"                     // terminal clear
#define RESIZE "resize -s 40 85"          // resize terminal
#define TAB_SIZE "tabs -6"                // terminal tab size
#define OPEN_DOCS "open Documentaion.pdf" // open game rule and user docs

#define DECK_SIZE 52
#define SUIT_COUNT 4
#define RANK_COUNT 13

#define MAX_LINE 86   // length + 1 of a line in terminal
#define MAX_INPUT 13  // only take in 13 chars (ignore space, comma, dot)
#define MAX_IN_CARD 4 // only take in 4 cards on a turn

struct card {         // represent a card
  unsigned int rank;  // card rank A, 2, 3,..., 10, J, Q, K
  unsigned int suit;  // card suit S, C, D, H
  unsigned int point; // card point = rank * 4 + suit (unique value)
};

struct player {              // represent a player
  unsigned int cards_num;    // number of card a player have at any given time
  struct card *player_cards; // cards that a player have
};

struct discard {                        // represent a discard card
  unsigned int player_name;             // name of player who play the card
  unsigned int played_card_num;         // number of cards played on a turn
  unsigned int card_point[MAX_IN_CARD]; // point of cards played on that turn
};

#endif
