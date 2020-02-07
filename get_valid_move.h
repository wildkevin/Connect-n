
//header of get_valid_move.c

#ifndef get_valid_move_h
#define get_valid_move_h

#include <stdbool.h>

int get_move(char** board, int num_cols);
bool is_valid_move(int num_args_read, int num_args_needed, char** board, int player_col, int num_cols);
bool is_valid_formatting(int num_args_read, int num_args_needed);
bool move_constraints_met(char** board, int player_col, int num_cols);
bool move_inside_board(int player_col, int num_cols);
bool is_blank_space(char** board, int player_col);

#endif /* get_valid_move_h */
