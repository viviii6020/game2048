#define _CRT_SECURE_NO_WARNINGS 1
#include "game3072.h"

int step = 0; //count steps in each play
 
void DisplayBoard(int board[ROW][COL])
{
    int i = 0;
    int j = 0;
    printf("tip�G*��V�䱱��������* ESC���^���*\n");
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
 
void init_num(int board[ROW][COL]) //generate number
{
	int x, y;
	x = rand() % ROW;
	y = rand() % COL;	
	board[x][y] = 3; //randomly generate 3  
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
		board[x][y] = 6;	
	return;
}

//function for move up				
void up(int board[ROW][COL])
{
	//initialize varible
	int i = 0; 
	int j = 0;
	int x = 0;
	int y = 0;
	for (i = 0; i < ROW; i++)
	{
		//move
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
		//merge
		for (j = 0; j < COL-1; j++)
			if (board[j][i] == board[j + 1][i] && board[j][i] != 0) 
			{											 
				board[j][i] = board[j][i] *2;
				board[j + 1][i] = 0;		
			}
		//move to fill again
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
	if (contrast(board) == 1&&check(board)==0)
		put_num(board);
	else
		return;
}


//function for move down 
void down(int board[ROW][COL])
{
	//initialize varible
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	for (i = 0; i < ROW; i++)
	{
		//move
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
		
		//merge
		for (j = COL-1; j > 0; j--)
			if (board[j][i] == board[j - 1][i] && board[j][i] != 0)
			{
				board[j][i] = board[j][i] *2;
				board[j - 1][i] = 0;			
			}
			
		//move to fill again
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
	if (contrast(board) == 1&&check(board)==0)
		put_num(board);
	else
		return;
}

//function for move left		
void left(int board[ROW][COL])
{
	//initialize varible
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	for (i = 0; i < ROW; i++)
	{
		//move
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
		
		//merge
		for (j = 0; j < 3; j++)
			if (board[i][j] == board[i][j + 1] && board[i][j] != 0)
			{
				board[i][j] = board[i][j] *2;
				board[i][j + 1] = 0;
			}
			
		//move to fill again
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
	if (contrast(board) == 1&&check(board)==0)
		put_num(board);
	else
		return;
}
 
//function for move right 
void right(int board[ROW][COL])
{
	//initialize varible
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	for (i = 0; i < 4; i++)
	{
		//move
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
		
		//merge
		for (j = 3; j > 0; j--)
			if (board[i][j] == board[i][j - 1] && board[i][j] != 0)
			{
				board[i][j] = board[i][j] *2;
				board[i][j - 1] = 0;
			}
			
		//move to fill again
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
	if (contrast(board) == 1&&check(board)==0)
		put_num(board);
	else
		return;
}

int check(int board[ROW][COL])
{
	int i,j;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (board[i][j] == 0) //there is still space(s), game continue.
				return 0;
			}
		}
		return 1;
}
//function to detect if the space is full and can't merge together
//which means "Fail the game".
int is_fail(int board[ROW][COL])
{
	int i = 0; 
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (board[i][j] == 0) //there is still space(s), game continue.
				return 0;
			if (i > 0)
			{
				//the spaces still can merge together, game continue.
				if (board[i - 1][j] == board[i][j])
					return 0;
			}
			if (j > 0)
			{
				//the spaces still can merge together, game continue.
				if (board[i][j - 1] == board[i][j])
					return 0;
			}
		}
	}
	return 1;
}
 
//function to detect if the gamer is win 
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
	if (num >= 3072) //win the game that return 1
		return 1;
	else
		return 0;
}

//copy current board
void copyboard(int board[ROW][COL], int copy[ROW][COL])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
		for (j = 0; j < COL; j++)
			copy[i][j] = board[i][j];
}

//determine the array is the same or not
int contrast(int board[ROW][COL])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			if (copy[i][j]==board[i][j])
				return 1;
	return 0;
}

//print the menu of the game 
void menu()
{
	printf("**************************\n");
	printf("*****�� 1 �} �l �C ��*****\n");
	printf("*****�� 0 �h �X �C ��*****\n");
	printf("**************************\n");
}

void game3072()
{
	int board[ROW][COL] = { {0} };
	int control = 0;
	DisplayBoard(board); 
	init_num(board);
	system("cls"); //Let the interface be clean
	DisplayBoard(board);
	while ((control = _getch()) != 0x1b)
	{ 
		switch (control)
		{
		case 0xe0:
			//control the direction
			switch (control = getch())
			{
			    case 72: 
					copyboard(board, copy);
				    up(board);
				    step++;
				    break;
			    case 80: 
					copyboard(board, copy);
			    	down(board);
			    	step++;
			    	break;
			    case 75: 
					copyboard(board, copy);
			    	left(board);
			    	step++;
				    break;
		    	case 77:  
					copyboard(board, copy);
		    		right(board);
		    		step++;
				    break;
		    	default:
			    	break;
			}
			
		system("cls");
		DisplayBoard(board);
		printf("�ثe���ʦ��ơG%d\n", step);
		
		//if the player win
		if (is_win(board) == 1)
		{
			printf("���ߧAĹ�F�I\n");
		}
		
		//if the player lose
		if (is_fail(board) == 1)
		{
			printf("�U���A�V�O�a�I\n");
		}
		}
	}	
}
 
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	
	//do while loop	
	do
	{	
		menu();
	    printf("�п�ܡG");
	    scanf("%d", &input);
	    
	    //Let the player choose if he want to play again or not 
		switch (input)
		{
		    case 1:
			    game3072();
			    break;
		    case 0:
		    	printf("�h�X�C���A���ŦA�Ӫ��r~\n");
		    	break;
		    default:
			    printf("���A�@�����s��ܪ����|\n");
		    	break;
		}
	} while (input);
	return 0;
}
