#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void IntBoard(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < ROW;i++)
	{
		for (j = 0; j < COL; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//打印一行数据
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
			else
				printf("\n");
		}
		//printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
		//打印分行符号
		if (i < row - 1)
		{
			for (int i = 0; i < col; i++)
			{
				if (i < col - 1)
					printf("---|");
				else
					printf("---\n");
			}
		}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("玩家走:>\n");
	while (1)
	{
		printf("请输入要下的坐标:>");
		scanf("%d%d", &x, &y);
		//判断坐标合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y-1] == ' ')
			{
				board[x - 1][y - 1] = '*';
			
				break;
			}
			else
			{
				printf("该坐标点被占用\n");
			}
		}
		else {
			printf("坐标非法，请重新输入\n");
		}
	}
}

void computerMove(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("电脑走\n");
	while (1)
	{
		x = rand() % COL;
		y = rand() % ROW ;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

char IsWin(char board[ROW][COL], int row, int col)
{
	int i;
	int isSame = FALSE;
	for (i = 0; i < row;i++)
	{
		for (int j = 1; j < col; j++)
		{
			if ((board[i][j] == board[i][j - 1]) && board[i][j] != ' ')
				continue;
			else if(i==2 && isSame==FALSE)
				goto turn1;
		}
		isSame = TRUE;
	}
	return board[i][1];
turn1:
	for (i = 0; i < col; i++)
	{
		for (int j = 1; j < row; j++)
		{
			if ((board[j][i] == board[j-1][i]) && board[j][i] != ' ')
				continue;
			else if (i == 2 && isSame == FALSE)
				goto turn2;
		}
		isSame = TRUE;
	}
	return board[1][i];
turn2:
	for (i = 1; i < col; i++)
	{
		if ((board[i - 1][i - 1] == board[i][i]) && board[i][i] != ' ')
			continue;
		else
			goto turn3;
	}
	return board[1][1];
turn3:
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
		return board[1][1];
	for (i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 'C';
		}
	}
	return 'V';

}