#pragma once
 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
 
#define ROW 4
#define COL 4
const int copy[ROW][COL];

//Initialize the game interface and print it
void DisplayBoard(int board[ROW][COL]);

//When the game start that randomly generate two "3"
void init_num(int board[ROW][COL]);

//Randomly place 3 or 6 after each move
void put_num(int board[ROW][COL]);

//Move steps
void up(int board[ROW][COL]);
void down(int board[ROW][COL]);
void left(int board[ROW][COL]);
void right(int board[ROW][COL]);

//Determine win or fail the game
int is_win(int board[ROW][COL]);
int is_fail(int board[ROW][COL]);
