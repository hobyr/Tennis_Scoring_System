#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void display_score(int player_1_score, int player_2_score);
int add_point_player(int player_score, bool deuce);
bool check_deuce(int player_1_score, int player_2_score);

int main(int argc, char *argv[])
{
  char player_1_name[20] = "";
  char player_2_name[20] = "";

  int player_1_sets = 0;
  int player_2_sets = 0;

  int player_1_games = 0;
  int player_2_games = 0;

  int player_1_score = 0;
  int player_2_score = 0;

  bool is_deuce = false;
  bool is_match_over = false;

  printf("Please start the match.");

  while (!is_match_over) {
    is_deuce = check_deuce(player_1_score, player_2_score);

    printf("Who won this point? [1 or 2] ");
    int player_point_won;
    scanf("%d", &player_point_won);

    if (is_deuce) {
      // Deuce game
      if (player_point_won == 1) {
        player_1_score = add_point_player(player_1_score, is_deuce);
      } else {
        player_2_score = add_point_player(player_2_score, is_deuce);
      }
    } else {
      // Normal game
      if (player_point_won == 1) {
        player_1_score = add_point_player(player_1_score, is_deuce);
      } else {
        player_2_score = add_point_player(player_2_score, is_deuce);
      }
    }
    display_score(player_1_score, player_2_score);
  }

  return 0;
}

void display_score(int player_1_score, int player_2_score)
{
  if (player_1_score == 45) {
    printf("AD - %d\n", player_2_score);
  } else if (player_2_score == 45) {
    printf("%d - AD\n", player_1_score);
  } else {
    printf("%d - %d\n", player_1_score, player_2_score);
  }
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
