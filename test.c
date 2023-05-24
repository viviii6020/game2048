#define _CRT_SECURE_NO_WARNINGS 1
#include "game2048.h"
  
void menu()
{
	printf("**************************n");
	printf("*****按 1 開 始 遊 戲*****n");
	printf("*****按 0 退 出 遊 戲*****n");
	printf("**************************n");
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
			printf("恭喜你贏了！n");
		}
		if (is_fail(board) == 1)
		{
			printf("哈哈哈哈哈哈哈好菜n");
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
		    	printf("退出遊戲，客官常來玩呀~)n");
		    	break;
		    default:
			    printf("給你一次重新選擇的機會n");
		    	break;
		}
	} while (input);
	return 0;
}
