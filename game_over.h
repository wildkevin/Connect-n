
//header of game_over.c

#ifndef game_over_h
#define game_over_h

#include <stdbool.h>

bool is_game_over(char** board, int num_rows, int num_cols, int pieces_to_win);
bool tie(char** board, int num_rows, int num_cols, int pieces_to_win);
bool win(char** board, int num_rows, int num_cols, int pieces_to_win);
bool row_win(char** board, int num_rows, int num_cols, int pieces_to_win);
bool required_pieces_inrow(char* array, int num_cols, int pieces_to_win, char character);
bool diag_win(char** board, int num_rows, int num_cols, int pieces_to_win);
bool left_diag_win(char** board, int num_rows, int num_cols, int pieces_to_win);
bool right_diag_win(char** board, int num_rows, int num_cols, int pieces_to_win);
bool col_win(char** board, int num_rows, int num_cols, int pieces_to_win);

#endif /* game_over_h */
