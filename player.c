#include "player.h"

void create_player(struct card *deck, struct player *player_list,
                   unsigned int player_num) {
  unsigned int cards_num = DECK_SIZE / player_num;

  for (int i = 0; i < player_num; i++) {
    player_list[i].cards_num = cards_num;
    player_list[i].player_cards = player_cards(deck, cards_num, i);
  }

  printf("Sucessfull create %i players...\n\vPlease assign each player with a number from 1 to %i in clockwise.\nAnd that will be player in game name.\n\vPress \"Enter\" to continue...", player_num,  player_num);
  while (getchar() != '\n');
  system(CLEAR);
}


struct card *player_cards(struct card *deck, unsigned int cards_num,
                          unsigned int player_count){
  struct card *cards_arr = malloc(cards_num * sizeof(struct card));
  unsigned int first_card = player_count * cards_num;

  for (unsigned int i = 0; i < cards_num; i++) {
    cards_arr[i] = deck[first_card + i];
  }

  shellSort_cards(cards_arr, cards_num);
  return cards_arr;
}


void print_player_cards(struct player *player, unsigned int player_name) {
  printf(" Player %i:\t", player_name);

  for (unsigned int i = 0; i < player->cards_num; i++) {
    if (i % 13 == 0 && i != 0) printf("\n\t\t");
    print_card(player->player_cards[player->cards_num - 1 - i]);
    printf("  ");
  }
  printf("\n\v");
}
