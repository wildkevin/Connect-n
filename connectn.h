
//header of connectn.c

#ifndef connectn_h
#define connectn_h


void declare_winner(char** board, int turn, int num_rows, int num_cols, int pieces_to_win);
void valid_input_commandline(int argc);
void play_connectn(int num_rows, int num_cols, int pieces_to_win);

#endif /* connectn_h */
