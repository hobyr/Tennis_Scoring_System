#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void display_score(int *players_scores) {
  printf("%d - %d\n", players_scores[0], players_scores[1]);
}

void display_name(char *player_name) {
  printf("%s\n", player_name);
}

int main(int argc, char *argv[])
{
  char player_1_name[20] = "Wolf";
  char player_2_name[20] = "Garin";

  int players_sets[2] = {0, 0};

  int players_games[2] = {0, 0};

  int players_score[2] = {0, 15};

  bool is_deuce = false;
  bool is_match_over = false;

  printf("Please start the match.\n");

  /*
  while (!is_match_over) {
    printf("Who won this point? [1 or 2] ");
    int player_point_won;
    scanf("%d", &player_point_won);

    if (is_deuce) {
      // Deuce game
    } else {
      // Normal game
    }
  }
  */

  display_score(players_score);
  display_name(player_2_name);

  return 0;
}


int add_point_player(int player_score, bool deuce)
{
  int new_score = 0;

  if (player_score == 0) {
    new_score = 15;  
  } else if (player_score == 15) {
    new_score = 30;
  } else if (player_score == 30) {
    new_score = 40;
  } else if (player_score == 40) {
    if (deuce) {
      new_score = 45;
    } else {
      new_score = 60;
    }
  } else if (player_score == 45) {
    if (deuce) {
      new_score = 40;
    } else {
      new_score = 60;
    }
  }

  return new_score;
}

bool check_deuce(int player_1_score, int player_2_score)
{
  if (player_1_score == 40 && player_2_score == 40) {
    return true;
  }
  return false;
}
