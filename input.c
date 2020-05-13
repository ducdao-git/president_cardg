#include "input.h"

void terminal_setup() {
  system(RESIZE);
  system(TAB_SIZE);
  system(CLEAR);
}


void player_num_scan(unsigned int *player_num) {
  unsigned int temp = 0;
  char *ptr, str[MAX_LINE];
  char msg[] = "Please choose between 2, 4, or 13 players only.\n\n";

  while (temp < 2 || DECK_SIZE % temp != 0 || temp > 13) {
    printf("Choose the number of player (2 / 4 / 13): ");
    fgets(str, sizeof(str), stdin);
    temp = strtol(str, &ptr, 10);

    if (ptr == str || *ptr != '\n') {
      printf("Please enter interger only (expecting 2, 4, or 13).\n\n");
      temp = 0;
    }
    else if (temp == 2 || temp == 4 || temp == 13) {
      *player_num = temp;
      break;
    }
    else if (temp == 0)
      printf("You can't play the game without You.\n%s", msg);
    else if (temp == 1)
      printf("This game hasn't support P vs. AI yet.\n%s", msg);
    else if(temp > 13)
      printf("Too many players will result in less fun.\n%s", msg);
    else
      printf("52 cards can't devide equally among %i players.\n%s", temp, msg);
  }
}


void card_scan(unsigned int *point) {
  char in_str[MAX_LINE], qf_str[MAX_INPUT];

  while (1) {
    printf("Enter a card or a set of cards: ");
    fgets(in_str, MAX_LINE, stdin);

    if (in_str[0] == '\n') continue;

    delete_blank(in_str, qf_str);

    for (int i = 0; i < MAX_IN_CARD; i++) point[i] = 0;

    switch (tolower(qf_str[0])) {
      case 'p': goto exit_func;
      case 'i':
        printf("Usage: <card_rank><card_suit>\n");
        printf("   Or: <card_rank><card_suit> <card_rank><card_suit>\n\v");
        continue;
    }

    unsigned int check, str_len = strlen(qf_str);

    if (qf_str[0] == '1') {
      check = is_10_card(qf_str, str_len, point);
      if (check == 0) continue;
    }
    else if (isdigit(qf_str[0])) {
      check = is_num_card(qf_str, str_len, point);
      if (check == 0) continue;
    }
    else {
      check = is_JQKA_card(qf_str, str_len, point);
      if (check == 0) continue;
    }

    if (duplicate_card(point) != 0) continue;

    break;
  }
  exit_func:;
}


void delete_blank(char *input_str, char *output_str) {
  unsigned int a = 0, b = 0;

  while (input_str[a] != '\0' && input_str[a] != '\n') {
    while (input_str[a] == ' ' || input_str[a] == '.' || input_str[a] == ',')
      a++;

    output_str[b] = input_str[a];
    a++;
    b++;
    output_str[b] = '\0';

    if (b == MAX_INPUT) break;
  }
}


int is_JQKA(char c) {
  char rank[] = "jqka";
  c = tolower(c);

  for (int i = 0; i < 4; i++) {
    if (c == rank[i]) {
      return (i + 11);
    }
  }

  return 0;
}


int is_suit(char c) {
  char suit[] = "scdh";
  c = tolower(c);

  for (int i = 0; i < 4; i++) {
    if (c == suit[i]) {
      return (i + 1); // suit value + 1
    }
  }
  return 0;
}


int is_10_card(char *str, unsigned int str_len, unsigned int *point) {
  unsigned int suit;

  for (int i = 0; i < str_len; i+=3) {
    suit = is_suit(str[i+2]);

    if (str[i] != '1') {
      printf("Cards must have the same rank to be a pair.\n\v");
      return 0;
    }
    else if (str[i+1] != '0' || suit == 0) {
      printf("Please make sure you enter valid card(s).\n");
      printf("Expecting <card_rank><card_suit>\n");
      printf("       Or <card_rank><card_suit> <card_rank><card_suit>\n\v");
      return 0;
    }

    point[i / 3] = 10 * 4 + suit - 1;
  }

  return 1;
}


int is_num_card(char *str, unsigned int str_len, unsigned int *point) {
  unsigned int suit;

  for (int i = 0; i < str_len; i+=2) {
    suit = is_suit(str[i+1]);

    if (str[i] != str[0]) {
      printf("Cards must have the same rank to be in set.\n\v");
      return 0;
    }
    else if (suit == 0) {
      printf("Please make sure you enter valid card(s).\n");
      printf("Expecting <card_rank><card_suit>\n");
      printf("       Or <card_rank><card_suit> <card_rank><card_suit>\n\v");
      return 0;
    }

    if (str[i] == '2') point[i / 2] = 15 * 4 + suit - 1;
    else point[i / 2] = atoi(&str[i]) * 4 + suit - 1;
  }

  return 1;
}


int is_JQKA_card(char *str, unsigned int str_len, unsigned int *point) {
  unsigned int rank, suit;

  for (int i = 0; i < str_len; i+=2) {
    rank = is_JQKA(str[i]);
    suit = is_suit(str[i+1]);

    if (str[i] != str[0]) {
      printf("Cards must have the same rank to be a pair.\n\v");
      return 0;
    }
    else if (rank == 0 || suit == 0) {
      printf("Please make sure you enter valid card(s).\n");
      printf("Expecting <card_rank><card_suit>\n");
      printf("       Or <card_rank><card_suit> <card_rank><card_suit>\n\v");
      return 0;
    }

    point[i / 2] = rank * 4 + suit - 1;
  }

  return 1;
}

int duplicate_card(unsigned int *point) {
  for (int a = 0; a < 3; a++) {
    for (int b = a + 1; b < 4; b++) {
      if (point[a] == point[b]) {
        if (point[a] == 0) return 0;
        printf("You have enter a card more than 1 time. Please re-enter your card.\n\v");
        return 1;
      }
    }
  }
  return 0;
}
