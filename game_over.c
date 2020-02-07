
//This program (based on the idea of "tic tac toe") will determine the someone has won or tie game

#include "game_over.h"

bool is_game_over(char** board, int num_rows, int num_cols, int pieces_to_win){
    //general game over function
    return win(board, num_rows, num_cols, pieces_to_win) || tie(board, num_rows, num_cols, pieces_to_win);
}

bool tie(char** board, int num_rows, int num_cols, int pieces_to_win){
    //check if it is tie nor not
    int row = 0;
    int col = 0;
    
    //check that there are no blank spaces
    for(row = 0; row < num_rows; ++row){
        for(col = 0; col < num_cols; ++col){
            if(board[row][col] == '*'){
                return false;
            }
        }
    }
    //it also depends on if someone wins even the board is full
    return !win(board, num_rows, num_cols, pieces_to_win);
}

bool win(char** board, int num_rows, int num_cols, int pieces_to_win){
    //three ways to win, row, column, diagonal
    return row_win(board, num_rows, num_cols, pieces_to_win) || col_win(board, num_rows, num_cols, pieces_to_win) || diag_win(board, num_rows, num_cols, pieces_to_win);
}

bool col_win(char** board, int num_rows, int num_cols, int pieces_to_win){
    //if there is a column win based on the pieces to win
    int col  = 0;
    int row  = 0;
    int i    = 0;
    int test = 0;
    
    if (pieces_to_win > num_rows){
    //no way to win
        return false;
    }
    else{
    /*
     The idea of following three loops is to go through each unit in each
     column, and if the unit(0) equals to the next unit(1), the next unit(2)
     equals to the  unit(0), and so on, depending on the pieces to win.
    */
        for(col = 0; col < num_cols; col++){
            for(row = 0; row <= (num_rows - pieces_to_win); row++){
                test = 0;
                for(i = 1; i < pieces_to_win; i++){
                    if (board[row][col] != '*' && board[row][col] == board[row + i][col]){
                        test++;
                    }
                }
                if (test == (pieces_to_win - 1)){
    /*
     The winning condition should be number of "pieces to win" pawn in a column.
     So the test point should be "pieces to win" minus one, because it only needs
     to check twice for (0) = (1) & (0) = (2)
    */
                    return true;
                }
            }
        }
    }
    return false;
}



bool row_win(char** board, int num_rows, int num_cols, int pieces_to_win){
    int row = 0;
    
    //set each row as an array and check the winning condition
    for(row = 0; row < num_rows; ++row){
        if(required_pieces_inrow(board[row], num_cols, pieces_to_win, 'X') || required_pieces_inrow(board[row], num_cols, pieces_to_win, 'O')){
            return true;
        }
    }
    return false;
}

bool required_pieces_inrow(char* array, int num_cols, int pieces_to_win, char character){
    //this function tests if there are "pieces to win" continued pawn in one row
    int col  = 0;
    int i    = 0;
    int test = 0;
    
    if (pieces_to_win > num_cols){
        return false;
    }
    
    else if (pieces_to_win == num_cols){
    //all the unit in the array should be same pawn if wins
        for(i = 0; i < num_cols; ++i){
            if(array[i] != character){
                return false;
            }
        }
        return true;
    }
    
    else{
        for(col = 0; col <= (num_cols - pieces_to_win); col++){
            test = 0;
            for(i = 1; i < pieces_to_win; i++){
                if (array[col] == character && array[col] == array[col + i]){
                    test++;
                }
            }
            if (test == (pieces_to_win - 1)){
    //same idea of function "col win"
                return true;
            }
        }
    }
    return false;
}


bool diag_win(char** board, int num_rows, int num_cols, int pieces_to_win){
    //general diagonal win function
   	return left_diag_win(board, num_rows, num_cols, pieces_to_win) || right_diag_win(board, num_rows, num_cols, pieces_to_win);
}

bool left_diag_win(char** board, int num_rows, int num_cols, int pieces_to_win){
    /*
     X
       X
         X
     */

    int row  = 0;
    int col  = 0;
    int i    = 0;
    int test = 0;
    
    char character = '?';
    
    if (pieces_to_win > num_cols || pieces_to_win > num_rows){
        return false;
    }
    
    else if (pieces_to_win == num_cols && pieces_to_win == num_rows){
    //all the unit on the diagonal should be the same, not"*", if wins
        character = board[0][0];
        if (character == '*'){
            return false;
        }
        else{
            for(i = 1; i < num_rows; ++i){
                if(board[i][i] != character){
                    return false;
                }
            }
            return true;
        }
    }
    
    else{
        for(row = 0; row <= (num_rows - pieces_to_win); ++row){
            for(col = 0; col <= (num_cols - pieces_to_win); ++col){
                test = 0;
                for(i = 1; i < pieces_to_win; ++i){
                    if (board[row][col] != '*' && board[row][col] == board[row + i][col + i]){
                        test++;
                    }
                }
                if (test == (pieces_to_win - 1)){
                //same idea of the test point (col win)
                    return true;
                }
            }
        }
    }
    return false;
}

bool right_diag_win(char** board, int num_rows, int num_cols, int pieces_to_win){
    /*
         X
       X
     X
     */
    //This function is similar to the "left_diag_win", only the index is different
    
    int row  = 0;
    int col  = 0;
    int i    = 0;
    int test = 0;
    
    char character = '?';
    
    if (pieces_to_win > num_cols || pieces_to_win > num_rows){
        return false;
    }
    
    else if (pieces_to_win == num_cols && pieces_to_win == num_rows){
        character = board[0][num_cols];
        if (character == '*'){
            return false;
        }
        else{
            for(i = 1; i < num_cols; ++i){
                if(board[i][num_cols - 1 -i] != character){
                    return false;
                }
            }
            return true;
        }
    }
    
    else{
        for(row = 0; row <= (num_rows - pieces_to_win); ++row){
            for(col = (num_cols - 1); col >= (pieces_to_win - 1); --col){
                test = 0;
                for(i = 1; i < pieces_to_win; ++i){
                    if (board[row][col] != '*' && board[row][col] == board[row + i][col - i]){
                        test++;
                    }
                }
                if (test == (pieces_to_win - 1)){
                //same idea of the test point (col win)
                    return true;
                }
            }
        }
    }
    return false;
}

