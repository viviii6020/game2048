#pragma once
 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
 
#define ROW 4
#define COL 4
const int copy[ROW][COL];

//��l�ƨæC�L�C������
void DisplayBoard(int board[ROW][COL]);
//�}���H���ͦ����2
void init_num(int board[ROW][COL]);
//�b���ʫ��H����m�Ʀ�2��4
void put_num(int board[ROW][COL]);
//����
void up(int board[ROW][COL]);
void down(int board[ROW][COL]);
void left(int board[ROW][COL]);
void right(int board[ROW][COL]);
//�P�w�ӭt
int is_win(int board[ROW][COL]);
int is_fail(int board[ROW][COL]);
