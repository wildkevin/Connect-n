
//This program (based on the idea of "tic tac toe") will include all the functions for the board

#include "board.h"
#include <stdlib.h>
#include <stdio.h>

void set_up(char*** board, int* turn, int num_rows, int num_cols){
    //this function will make the board, and define the turn
    *board = make_board(num_rows, num_cols);
    *turn = 0; //player 1 is 0, player 2 is 1
}

char** make_board(int num_rows, int num_cols){
    //this function will create the corresponding space in the memory
    int i = 0;
    int j = 0;
    char blank_space = '*';
    
    char** board = (char**)malloc(num_rows * sizeof(char*));
    //create the sapce for the row first
    
    for(i = 0; i < num_rows; ++i){
        //create the space for each column
        board[i] = (char*)malloc(num_cols * sizeof(char));
        for(j = 0; j < num_cols; ++j){
            board[i][j] = blank_space;
        }
    }
    return board;
}

void display_board(char** board, int num_rows, int num_cols){
    //display what the board look like
    
    int row = 0;
    int col = 0;
    int i   = 0;
    int j   = 0;
    
    for(i = num_rows - 1, row = 0; i >= 0 ; --i, ++row){
    /*this loop will print the row number from largest to 0, and
     print each element in the board
    */
        printf("%d ", i);
        for(col = 0; col < num_cols; ++col){
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
    
    printf("  ");
    for(j = 0; j < num_cols; ++j){
        //print the column number
        printf("%d ", j);
    }
    printf("\n");
}

void clean_up(char*** board, int num_rows){
    //this function will clean the space in the memory
    int row;
    
    for(row = 0; row < num_rows; ++row){
        free((*board)[row]);
    }
    free(*board);
    
    *board = NULL;
    //set the board to nothing
}
