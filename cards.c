#include "cards.h"

void initialize_deck(struct card *deck) {
  // create card deck
  unsigned int i = 0;

  for (unsigned int suit = 0; suit < SUIT_COUNT; suit++) {
    for (unsigned int rank = 0; rank < RANK_COUNT; rank++) {
      deck[i].rank = rank + 3;
      deck[i].suit = suit;
      deck[i].point = deck[i].rank * 4 + deck[i].suit;
      i++;
    }
  }

  // print out card deck
  for (unsigned int i = 0; i < DECK_SIZE; i++) {
    if (i == 0) printf("\t\t\tInitialize A Deck Of Card:\n");
    if (i % 13 == 0 && i != 0) putchar('\n');
    if (i % 13 == 0) printf("\t\t\t");

    print_card(deck[i]);
    printf("  ");
  }
  printf("\n\n");

  suffle_cards(deck);
}


void print_card(struct card card) {
  char rank[] = "JQKA2";
  char suits[] = "SCDH";

  if (card.rank % 15 > 10 || card.rank % 15 == 0)
    printf("%c%c", rank[card.rank % 11], suits[card.suit]);
  else
    printf("%i%c", card.rank, suits[card.suit]);
}


void point_to_card(struct card *card, unsigned int point) {
  card->rank = point / 4;
  card->suit = point % 4;
  card->point = point;
}


void swap_card(struct card *card_1, struct card *card_2) {
  struct card temp = *card_1;
  *card_1 = *card_2;
  *card_2 = temp;
}


void suffle_cards(struct card *deck) {
  srand(time(NULL));

  for (unsigned int i = 0; i < DECK_SIZE - 1; i++) {
    unsigned int i2 = rand() % (DECK_SIZE - i) + i;
    swap_card(&deck[i], &deck[i2]);
  }
}


void shellSort_cards(struct card *card_list, int cards_num) {
  if (cards_num < 2) return;
  // Rearrange elements at each n/2, n/4, n/8, ... intervals
  for (int gap = cards_num / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < cards_num; i += 1) {
      struct card temp = card_list[i];

      int j;
      for (j = i; j >= gap && temp.point > card_list[j - gap].point; j -= gap) {
          card_list[j] = card_list[j - gap];
      }

      card_list[j] = temp;
    }
  }
}


void delete_card(struct player *player, unsigned int *point) {
  // shifting all card after delete card to left (i) <- (i+1)
  for (int i = 0; i < MAX_IN_CARD && point[i] != 0; i++) {
    for (int a = card_index(player, point[i]); a < player->cards_num - 1; a++) {
      player->player_cards[a] = player->player_cards[a+1];
    }
    point_to_card(&player->player_cards[player->cards_num - 1], 0);
    player->cards_num--;
  }
}


int is_player_card(struct player *player, unsigned int *point) {
  int index;
  struct card blank;

  for (int i = 0; i < MAX_IN_CARD && point[i] != 0; i++) {
    index = card_index(player, point[i]);

    if (index == -1) {
      printf("You don't have the card ");
      point_to_card(&blank, point[i]);
      print_card(blank);
      printf("\n\v");
      return 0;
    }
  }

  return 1;
}


int card_index(struct player *player, unsigned int point) {
  int first_i = 0, last_i = player->cards_num - 1;

	while (first_i <= last_i &&
         point <= player->player_cards[first_i].point &&
         point >= player->player_cards[last_i].point) {

    if (first_i == last_i){
      if (player->player_cards[first_i].point == point)
        return first_i;
      else
        return -1;
    }

    int pos = first_i + (point - player->player_cards[last_i].point) *
              (last_i - first_i) / (player->player_cards[first_i].point -
              player->player_cards[last_i].point);

		if (player->player_cards[pos].point == point) return pos;

		if (player->player_cards[pos].point > point) first_i = pos + 1;
    else last_i = pos - 1;
	}

	return -1;
}


void print_discard_pile(unsigned int player_num, unsigned int turn_count,
                        struct discard *pile, struct player *player_list) {
  struct card blank;
  unsigned int player_name;

  printf("Previous played card: ");
  if (player_num > 2) putchar('\n');

  for (int i = 0; i < player_num - 1 && i <= turn_count; i++) {
    player_name = pile[turn_count - i].player_name;
    printf(" p%i (%i): ", player_name, player_list[player_name - 1].cards_num);

    for (int a = 0; a < pile[turn_count - i].played_card_num; a++) {
      point_to_card(&blank, pile[turn_count - i].card_point[a]);
      print_card(blank);
      putchar(' ');
    }

    printf(" | ");
    if (i != 0 && i%4 == 0) putchar('\n');
  }

  printf("\n\v");
}
