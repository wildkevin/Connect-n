
//header of board.c

#ifndef board_h
#define board_h

#include <stdio.h>

void set_up(char*** board, int* turn, int num_rows, int num_cols);
char** make_board(int num_rows, int num_cols);
void display_board(char** board, int num_rows, int num_cols);
void clean_up(char*** board, int num_rows);

#endif /* board_h */
