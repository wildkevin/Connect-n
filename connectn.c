
//This program (based on the idea of "tic tac toe") is the final program for running the game

#include "connectn.h"
#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "get_valid_move.h"
#include "game_over.h"
#include "play.h"

void declare_winner(char** board, int turn, int num_rows, int num_cols, int pieces_to_win){
    //this function will declare the winner based on the turn and the board
    
    if(win(board, num_rows, num_cols, pieces_to_win)){
    /*since the game function will still change the turn after someone
     has already won the game, turn(1) means player 1 (0) win
     */
        if(turn == 1){
            printf("Player 1 Won!\n");
        }
        else{
            printf("Player 2 Won!\n");
        }
    }
    //if no one has won, tie game
    else{
        printf("Tie game!\n");
    }
}

void play_connectn(int num_rows, int num_cols, int pieces_to_win){
    //the function for the whole game
    
    char** board   = NULL;
    int turn       = 0;
    int player_col = 0;
    //set up
    set_up(&board, &turn, num_rows, num_cols);
    
    //play _game
    while(!is_game_over(board, num_rows, num_cols, pieces_to_win)){
    //play the game until tie or someone has won
        display_board(board, num_rows, num_cols);
        player_col = get_move(board, num_cols);
        play_move(board, num_rows, player_col, turn);
        change_turn(&turn);
    }
    
    display_board(board, num_rows, num_cols);
    declare_winner(board, turn, num_rows, num_cols, pieces_to_win);
    clean_up(&board, num_rows);
}

void valid_input_commandline(int argc){
    //check the initial input are valid or not
    
    if (argc != 4){
        if (argc < 4) {
            printf("Not enough arguments entered\n");
        }
        if (argc > 4){
            printf("Too many arguments entered\n");
        }
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }
}

int main(int argc, char* argv[]){
    
    valid_input_commandline(argc);
    
    //change the number(string) to integer
    int num_rows      = atoi(argv[1]);
    int num_cols      = atoi(argv[2]);
    int pieces_to_win = atoi(argv[3]);
    
    play_connectn(num_rows, num_cols, pieces_to_win);
    
    return 0;
}
