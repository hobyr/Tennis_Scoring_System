#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Display the score in a readable format.
void display_score(int *players_scores) {
  printf("%d - %d\n", players_scores[0], players_scores[1]);
}

// Display the name of a player
void display_name(char *player_name) {
  printf("%s\n", player_name);
}

// Modify the score of a player
int add_point_player(int player_score)
{
  int new_score;

  if (player_score == 0) {
    new_score = 15;  
  } else if (player_score == 15) {
    new_score = 30;
  } else if (player_score == 30) {
    new_score = 40;
  } else if (player_score == 40) {
    new_score = 60;
  }
  return new_score;
}

// Check for deuce situation in a game
void check_deuce(int *players_scores, bool *is_deuce)
{
  if (players_scores[0] == 40 && players_scores[1] == 40) {
    *is_deuce = true;
  } else {
    *is_deuce = false;
  }
}

int main(int argc, char *argv[])
{
  char player_1_name[20] = "Wolf";
  char player_2_name[20] = "Garin";

  int players_sets[2] = {0, 0};

  int players_games[2] = {0, 0};

  int players_score[2] = {0, 0};

  bool is_deuce = false;
  bool is_advantage = false;
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
  players_score[0] = add_point_player(players_score[0]);
  display_score(players_score);
  check_deuce(players_score, &is_deuce);
  printf("Deuce? %d\n", is_deuce);
  players_score[0] = add_point_player(players_score[0]);
  display_score(players_score);
  check_deuce(players_score, &is_deuce);
  printf("Deuce? %d\n", is_deuce);
  players_score[1] = add_point_player(players_score[1]);
  display_score(players_score);
  check_deuce(players_score, &is_deuce);
  printf("Deuce? %d\n", is_deuce);
  players_score[1] = add_point_player(players_score[1]);
  display_score(players_score);
  check_deuce(players_score, &is_deuce);
  printf("Deuce? %d\n", is_deuce);
  players_score[0] = add_point_player(players_score[0]);
  display_score(players_score);
  check_deuce(players_score, &is_deuce);
  printf("Deuce? %d\n", is_deuce);
  players_score[1] = add_point_player(players_score[1]);
  display_score(players_score);
  check_deuce(players_score, &is_deuce);
  printf("Deuce? %d\n", is_deuce);

  return 0;
}
