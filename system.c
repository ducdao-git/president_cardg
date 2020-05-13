#include "system.h"

void game_play(struct player *player_list, unsigned int player_num,
               struct discard *pile) {

  unsigned int first_player = rand() % player_num;
  printf("Player %u will go first... Player %u, press \"Enter\" to see your card...", first_player + 1, first_player + 1);

  // turn_count count of time a player played a card
  unsigned int pass_count = 0, turn_count = 0, point_sum = 0;
  unsigned int player_index = first_player, in_card_point[MAX_IN_CARD];

  while (getchar() != '\n');

  while (1) {
    putchar('\v');
    print_player_cards(&player_list[player_index], player_index + 1);

    // sum all the card point from last turn
    if (turn_count > 0 && point_sum != 0) {
      point_sum = 0;
      for (int i = 0; i < pile[turn_count - 1].played_card_num; i++) {
        point_sum += pile[turn_count - 1].card_point[i];
      }
    }
    // ------------------------------------- //

    unsigned int played_card_num;
    if (turn_count > 0) played_card_num = pile[turn_count - 1].played_card_num;
    else played_card_num = 0;

    printf("Enter \"p\" for pass or \"i\" for input card instruction\n");
    card_process(&player_list[player_index], player_index + 1, point_sum,
                 played_card_num, in_card_point);

    // add 1 to not skip the above if when loop
    point_sum++;

    /* set point_sum to 0 if all other player pass
       else put the in card in discard pile.*/
    if (in_card_point[0] == 0) {
      pass_count++;
      if (pass_count == player_num - 1) {
        point_sum = 0;
        pass_count = 0;
      }
    }
    else {
      pile[turn_count].player_name = player_index + 1;

      for (int i = 0; i < MAX_IN_CARD && in_card_point[i] != 0; i++) {
        pile[turn_count].played_card_num = i + 1;
        pile[turn_count].card_point[i] = in_card_point[i];
      }

      turn_count++;
    }
    // ------------------------------------- //

    system(CLEAR);

    if (player_list[player_index].cards_num == 0) {
      printf("Player %i has won the game.\n", player_index + 1);
      printf("Player %i is now the President of United State of America.\n\v",
             player_index + 1);
      break;
    }

    print_discard_pile(player_num, turn_count - 1, pile, player_list);

    player_index = (player_index + 1) % player_num;
    printf("Player %u go next... Player %u, press \"Enter\" to see your card...", player_index + 1, player_index + 1);

    while (getchar() != '\n');
  }

}


void card_process(struct player *player, unsigned int player_name,
                  unsigned int point_sum, unsigned int played_card_num, unsigned int *point) {
  unsigned int in_card_count, in_point_sum;

  while (1) {
    in_card_count = 0;
    in_point_sum = 0;

    card_scan(point);

    if (point_sum != 0) {
      if (point[0] == 0) return;

      for (int i = 0; i < MAX_IN_CARD && point[i] != 0; i++) {
        in_point_sum += point[i];
        in_card_count++;
      }

      if (in_card_count != played_card_num) {
        if (played_card_num == 1) printf("Can only play 1 card.\n\v");
        else printf("Need to play %u cards.\n\v", played_card_num);

        continue;
      }

      if (point_sum >= in_point_sum) {
        if (played_card_num == 1)
          printf("This card cannot win over the previous card.\n\v");
        else
          printf("These cards cannot win over the previous cards.\n\v");

        continue;
      }
    }
    else if (point[0] == 0) {
      printf("Cannot pass this turn. You are the first player in this round.\n\v");
      continue;
    }

    if (is_player_card(player, point) == 0) continue;

    break;
  }

  delete_card(player, point);

  if (player->cards_num == 0) return;

  if (point[0] != 0) {
    printf("Sucessfull played your card...\n\v");
    print_player_cards(player, player_name);
    printf("Press \"Enter\" to call the next player...");
    while (getchar() != '\n');
  }
}


void welcome() {
  printf("\v\t\t\t\t\t    President Card Game\n\v");

  printf("Enter \"p\" to start play the game or \"r\" for game rule and user documentation: ");

  int c;
  while (1) {
    c = getchar();
    fflush(stdin);

    if (c == 82 || c == 114) {
      system(OPEN_DOCS);
      system(CLEAR);
      break;
    }
    else if (c == 80 || c == 112) {
      system(CLEAR);
      break;
    }
    else printf("Enter \"p\" or \"r\" only: ");
  }
}
