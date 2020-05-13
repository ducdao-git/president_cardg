#include "system.h"

int main() {
  /*-------------------- game setup --------------------*/
  terminal_setup();
  welcome();

  struct card deck[DECK_SIZE];
  initialize_deck(deck);

  unsigned int player_num;
  player_num_scan(&player_num);

  struct player player_list[player_num];
  create_player(deck, player_list, player_num);


  /*---------------------- in game ---------------------*/
  struct discard pile[DECK_SIZE];
  game_play(player_list, player_num, pile);


  /*-------------------- finish game -------------------*/
  printf("All player remaining card(s):\n\v");
  for(unsigned int a = 0; a < player_num; a++) {
    print_player_cards(&player_list[a], a + 1);
    free(player_list[a].player_cards);
  }

  return 0;
}
