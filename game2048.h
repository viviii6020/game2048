#pragma once
 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
 
#define ROW 4
#define COL 4
const int copy[ROW][COL];

//初始化並列印遊戲介面
void DisplayBoard(int board[ROW][COL]);
//開局隨機生成兩個2
void init_num(int board[ROW][COL]);
//在移動後隨機放置數位2或4
void put_num(int board[ROW][COL]);
//移動
void up(int board[ROW][COL]);
void down(int board[ROW][COL]);
void left(int board[ROW][COL]);
void right(int board[ROW][COL]);
//判定勝負
int is_win(int board[ROW][COL]);
int is_fail(int board[ROW][COL]);
