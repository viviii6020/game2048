#define _CRT_SECURE_NO_WARNINGS 1
#include "game2048.h"
 
void DisplayBoard(int board[ROW][COL])
{
    int i = 0;
    int j = 0;
    printf("tip：*方向鍵控制方塊移動 *ESC鍵返回選單*\n");
    for (j = 0; j < COL; j++)
        printf("+-----");
    printf("+\n");
    for (i = 0; i < ROW; i++)
    {
        for (j= 0; j < COL; j++)
        {
            printf("|");
            if (board[i][j]!=0)
                printf("%5d", board[i][j]);
 
            else
                printf("     ");
        }
        printf("|\n");
        for (j = 0; j < COL; j++)
        {
            printf("+-----");
        }
        printf("+\n");
    }    
}
 
void init_num(int board[ROW][COL]) //生成數字 
{
	int x, y;
	x = rand() % ROW;
	y = rand() % COL;	
	board[x][y] = 3; //隨機在一個位置生成2
	x = rand() % ROW;
	y = rand() % COL;
	while (board[x][y] == 3) 
    {
		x = rand() % ROW;
		y = rand() % COL;
	}
	board[x][y] = 3; 
	return;
}
 
void put_num(int board[ROW][COL])
{
	int x = 0;
	int y = 0; 
	int z = 0;	
	x = rand() % ROW;
	y = rand() % COL;
	while (board[x][y] !=0)
	{
		x = rand() % ROW;
		y = rand() % COL;
	}
	z = rand() % 10;
	if (z<9)	
		board[x][y] = 3;	
	else	
		board[x][y] = 9;	
	return;
}
				
void up(int board[ROW][COL])
{
	int i = 0; 
	int j = 0;
	int x = 0;
	int y = 0;
	for (i = 0; i < ROW; i++)
	{
		//移動
		j = 0;
		y = 0;
		while (j < COL-1 && y < COL-1 )
		{
			if (board[j][i] == 0) 
			{
				for (x = j; x < ROW-1; x++)
					board[x][i] = board[x + 1][i];
				board[ROW-1][i] = 0;	
				y++;
			}
			else
				j++; 
		}
		//合併
		for (j = 0; j < COL-1; j++)
			if (board[j][i] == board[j + 1][i] && board[j][i] != 0) 
			{											 
				board[j][i] = board[j][i] * 3;
				board[j + 1][i] = 0;		
			}
		//再次移動補空
		j = 0;
		y = 0;
		while (j < COL - 1 && y < COL - 1)
		{
			if (board[j][i] == 0)
			{
				for (x = j; x < ROW - 1; x++)
					board[x][i] = board[x + 1][i];
				board[ROW - 1][i] = 0;
				y++;
			}
			else
				j++;
		}
	}
	if (contrast(board) == 0)
		put_num(board);
	else
		return;
}
 
void down(int board[ROW][COL])
{
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	for (i = 0; i < ROW; i++)
	{
		j = COL-1;
		y = 0;
		while (j > 0 && y < COL-1)
		{
			if (board[j][i] == 0)
			{
				for (x = j; x > 0; x--)
					board[x][i] = board[x - 1][i];
				board[0][i] = 0;
				y++;
			}
			else 
				j--;
		}
		for (j = COL-1; j > 0; j--)
			if (board[j][i] == board[j - 1][i] && board[j][i] != 0)
			{
				board[j][i] = board[j][i] * 3;
				board[j - 1][i] = 0;			
			}
		j = COL - 1;
		y = 0;
		while (j > 0 && y < COL - 1)
		{
			if (board[j][i] == 0)
			{
				for (x = j; x > 0; x--)
					board[x][i] = board[x - 1][i];
				board[0][i] = 0;
				y++;
			}
			else
				j--;
		}
	}
	if (contrast(board) == 0)
		put_num(board);
	else
		return;
}
			
void left(int board[ROW][COL])
{
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	for (i = 0; i < ROW; i++)
	{
		j = 0; 
		y = 0;
		while (j < 3 && y < 3 )
		{
			if (board[i][j] == 0)
			{
				for (x = j; x < ROW-1; x++)
					board[i][x] = board[i][x + 1];
				board[i][COL-1] = 0;
				y++;
			}
			else
				j++;
		}
		for (j = 0; j < 3; j++)
			if (board[i][j] == board[i][j + 1] && board[i][j] != 0)
			{
				board[i][j] = board[i][j] * 3;
				board[i][j + 1] = 0;
			}
		j = 0; 
		y = 0;
		while (j < 3 && y < 3)
		{
			if (board[i][j] == 0)
			{
				for (x = j; x < ROW - 1; x++)
					board[i][x] = board[i][x + 1];
				board[i][COL - 1] = 0;
				y++;
			}
			else
				j++;
		}
	}
	if (contrast(board) == 0)
		put_num(board);
	else
		return;
}
 
void right(int board[ROW][COL])
{
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	for (i = 0; i < 4; i++)
	{
		j = COL-1;
		y = 0;
		while (j>0 && y < COL-1)
		{
			if (board[i][j] == 0)
			{
				for (x = j; x > 0; x--)
					board[i][x] = board[i][x - 1];
				board[i][0] = 0;
				y++;
			}
			else j--;
		}
		for (j = 3; j > 0; j--)
			if (board[i][j] == board[i][j - 1] && board[i][j] != 0)
			{
				board[i][j] = board[i][j] * 3;
				board[i][j - 1] = 0;
			}
		j = COL - 1;
		y = 0;
		while (j > 0 && y < COL - 1)
		{
			if (board[i][j] == 0)
			{
				for (x = j; x > 0; x--)
					board[i][x] = board[i][x - 1];
				board[i][0] = 0;
				y++;
			}
			else j--;
		}
	}
	if (contrast(board) == 0)
		put_num(board);
	else
		return;
}
 
int is_fail(int board[ROW][COL])
{
	int i = 0; 
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (board[i][j] == 0)
				return 0;
			if (i > 0)
			{
				if (board[i - 1][j] == board[i][j])
					return 0;
			}
			if (j > 0)
			{
				if (board[i][j - 1] == board[i][j])
					return 0;
			}
		}
	}
	return 1;
}
 
int is_win(int board[ROW][COL])
{	
	int i = 0;
	int j = 0;
	int num = 0;
	for (i = 0; i < ROW; i++)
		for (j = 0; j < COL; j++)
		{
			if (board[i][j] > num)
				num = board[i][j];
		}
	if (num >= 59049)
		return 1;
	else
		return 0;
}
 
void copyboard(int board[ROW][COL],int copy[ROW][COL])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
		for (j = 0; j < COL; j++)
			copy[i][j] = board[i][j];
}
 
int contrast(int board[ROW][COL])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			if (copy[i][j] != board[i][j])
				return 0;
	return 1;
}


void menu()
{
	printf("**************************\n");
	printf("*****按 1 開 始 遊 戲*****\n");
	printf("*****按 0 退 出 遊 戲*****\n");
	printf("**************************\n");
}
 
void game2048()
{
	int board[ROW][COL] = { {0} };
	int control = 0;
	DisplayBoard(board); 
	init_num(board);
	system("cls"); //清屏，美觀介面
	DisplayBoard(board);
	while ((control = _getch()) != 0x1b)
	{ 
		switch (control)
		{
		case 0xe0:
			switch (control = getch())
			{
			    case 72: 
					copyboard(board, copy);
				    up(board);
				    break;
			    case 80: 
					copyboard(board, copy);
			    	down(board);
			    	break;
			    case 75: 
					copyboard(board, copy);
			    	left(board);
				    break;
		    	case 77:  
					copyboard(board, copy);
		    		right(board);
				    break;
		    	default:
			    	break;
			}
			
		system("cls");
		DisplayBoard(board);
		if (is_win(board) == 1)
		{
			printf("恭喜你贏了！\n");
		}
		if (is_fail(board) == 1)
		{
			printf("哈哈哈哈哈哈哈好菜\n");
		}
		}
	}	
}
 
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));	
	do
	{	menu();
	    printf("請選擇：");
	    scanf("%d", &input);
		switch (input)
		{
		    case 1:
			    game2048();
 
			    break;
		    case 0:
		    	printf("退出遊戲，客官常來玩呀~)\n");
		    	break;
		    default:
			    printf("給你一次重新選擇的機會\n");
		    	break;
		}
	} while (input);
	return 0;
}
