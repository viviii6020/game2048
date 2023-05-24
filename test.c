#define _CRT_SECURE_NO_WARNINGS 1
#include "game2048.h"
  
void menu()
{
	printf("**************************n");
	printf("*****�� 1 �} �l �C ��*****n");
	printf("*****�� 0 �h �X �C ��*****n");
	printf("**************************n");
}
 
void game2048()
{
	int board[ROW][COL] = { {0} };
	int control = 0;
	DisplayBoard(board); 
	init_num(board);
	system("cls"); //�M�̡A���[����
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
			printf("���ߧAĹ�F�In");
		}
		if (is_fail(board) == 1)
		{
			printf("���������������n��n");
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
	    printf("�п�ܡG");
	    scanf("%d", &input);
		switch (input)
		{
		    case 1:
			    game2048();
 
			    break;
		    case 0:
		    	printf("�h�X�C���A�ȩx�`�Ӫ��r~)n");
		    	break;
		    default:
			    printf("���A�@�����s��ܪ����|n");
		    	break;
		}
	} while (input);
	return 0;
}
