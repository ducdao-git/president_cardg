#ifndef INPUT_SEEN
#define INPUT_SEEN

#include "macro_lib.h"

/*
 * Purpose: set up the tab size and dimension for terminal, then clear it out.
*/
void terminal_setup();

/*
 * Purpose: scan in number of player and print out message if not receive desier number.

 * Parameters:
      player_num - store number of player here if scan is sucess
*/
void player_num_scan(unsigned int *player_num);

/*
 * Purpose: scan in 1 to 4 cards, pass or print out intruction for how to input a card. Will print an error message if input card not meet requirement.

 * Parameters:
      point - scan in card will be convert to point and store in this array
*/
void card_scan(unsigned int *point);

/*
 * Purpose: take all characters that not space, comma, or dot in the input strig and store it on the output string.

 * Parameters:
      input_str - the original string where the character will be take from
      output_str - store characters that not space, comma or dot
*/
void delete_blank(char *input_str, char *output_str);

/*
 * Purpose: see if a character is J, Q, K, or A (it doesn't care about upercase and lowercase).

 * Parameters:
      c - the character will be compare with J, Q, K, A

 * Return Value:
      . return the rank value if c is J, Q, K, or A
      . return 0 if c not J, Q, K, or A
*/
int is_JQKA(char c);

/*
 * Purpose: see if a character is S, C, D, or H - representation of a card suit S (it doesn't care about upercase and lowercase).

 * Parameters:
      c - the character will be compare with S, C, D, H

 * Return Value:
      . return the suit value + 1 if c is S, C, D, or H
      . return 0 if c not S, C, D, or H
*/
int is_suit(char c);

/*
 * Purpose: see if a string repesent 10 card(s) like 10S, 10C, 10D, 10H.

 * Parameters:
      str - string have it element compare to 10 card format
      str_len - length of the str
      point - if str does repesent 10 card(s) the card point of these 10 card
              will be store in point array

 * Return Value:
      . return 1 if str represent 10 card(s)
      . return 0 if str not represent 10 card(s)
*/
int is_10_card(char *str, unsigned int str_len, unsigned int *point);

/*
 * Purpose: see if a string repesent number card(s) like 2H, 4C, 9D, etc.

 * Parameters:
      str - string have it element compare to number card format
      str_len - length of the str
      point - if str does repesent number card(s) the card point of these number card will be store in point array

 * Return Value:
      . return 1 if str represent number card(s)
      . return 0 if str not represent number card(s)
*/
int is_num_card(char *str, unsigned int str_len, unsigned int *point);

/*
 * Purpose: see if a string repesent J, Q, K, or A card(s) like JH, QC, AD, etc.

 * Parameters:
      str - string have it element compare to number card format
      str_len - length of the str
      point - if str does repesent number card(s) the card point of these number card will be store in point array

 * Return Value:
      . return 1 if str represent J, Q, K, or A card(s)
      . return 0 if str not represent J, Q, K, or A card(s)
*/
int is_JQKA_card(char *str, unsigned int str_len, unsigned int *point);

/*
 * Purpose: see if a card is repeat by see if an element in point equal to another.

 * Parameters:
      point - array that have input card point store. This array will be look at an see if an element if repet.

 * Return Value:
      . return 1 if a card point is repeat (a repeat card)
      . return 0 if no card point is repeat (no repeat card)
*/
int duplicate_card(unsigned int *point);

#endif
