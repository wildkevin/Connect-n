
//This program (based on the idea of "tic tac toe") will play the valid move and change turn

#include "play.h"

void play_move(char** board, int num_rows, int player_col, int turn){
    //based on the turn (0 or 1), play the move
    char pieces[] = "XO";
    int i         = 0;
    
    for(i = (num_rows - 1); i >= 0; i--){
    /*put the pawn in the lowest row, which is not occupied by pawn,
     in the column user wants
     */
        if(board[i][player_col] == '*'){
            board[i][player_col] = pieces[turn];
            return;
        }
    }
}

void change_turn(int* turn){
    
    //since the turn only can be 0 or 1, this function will change between 0 and 1
    *turn = (*turn + 1) % 2;
}
