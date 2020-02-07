
//This program (based on the idea of "tic tac toe") will get the move and ensure it is a valid move

#include "get_valid_move.h"
#include <stdio.h>
#include <ctype.h>

int get_move(char** board, int num_cols){
    //get move function, if it is a valid move, it will return the column number
    int num_args_read = 0;
    int player_col    = 0;
    
    do{
        printf("Enter a column between 0 and %d to play in: \n", (num_cols - 1));
        //index = column - 1
        num_args_read = scanf("%d", &player_col);
        
    }while(!is_valid_move(num_args_read, 1, board, player_col, num_cols));
    
    return player_col;
}

bool is_valid_move(int num_args_read, int num_args_needed, char** board, int player_col, int num_cols){
    //it is the general function for valid move
    
    return is_valid_formatting(num_args_read, num_args_needed) &&
    move_constraints_met(board, player_col, num_cols);
    //valid move if the format and move is valid
}

bool is_valid_formatting(int num_args_read, int num_args_needed){
    /* check if the format on the entered input is correct
     @num_args_read: the number of format specifiers filled in by scanf
     @num_args_needed: the number of format specifiers you expected to be filled in
     @returns: true if the format is correct and false otherwise
     @side effects: consumes all characters on the standard input
     */
    char new_line = '\n';
    bool is_valid = true; //assume the format is correct
    if(num_args_read != num_args_needed){ //didn't fill in all the format specifiers
        is_valid = false;//format is not correct
    }
    
    do{
        scanf("%c", &new_line); //read the next character from the standard input
        if(!isspace(new_line)){ //if it isn't white space
            is_valid = false; //extra stuff there so format isn't valid
        }
    }while(new_line != '\n'); //keep reading characters until you reach the new line character
    return is_valid;
}

bool move_constraints_met(char** board, int player_col, int num_cols){
    //ensure the move is valid if the format is valid
    return move_inside_board(player_col, num_cols) && is_blank_space(board, player_col);
    
}

bool move_inside_board(int player_col, int num_cols){
    //move should be in the board
    return player_col >= 0 && player_col < num_cols;
}

bool is_blank_space(char** board, int player_col){
    //move should not made if there has already a pawn in it
    return board[0][player_col] == '*';
}
