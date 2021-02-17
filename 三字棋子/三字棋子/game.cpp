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
	printf("玩家走:>\t");
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


int sameJudge(char board[ROW][COL], int row_col, int num)//行为1 ，列为0
{
	//int isSame = FALSE;
	switch (row_col)
	{
	case 1:
		for (int i = 1; i < COL; i++)
		{
			if (board[num][i - 1] == board[num][i] && board[num][i] != ' ')
				//isSame = TRUE;
				continue;
			else
				return 0;

		}
		break;
	case 0:
		for (int i = 1; i < ROW; i++)
		{
			if (board[i - 1][num] == board[i][num] && board[i][num] != ' ')
				//isSame = TRUE;
				continue;
			else
				return 0;
		}
		break;
		return 1;
	}
}

char IsWin(char board[ROW][COL], int row, int col)
{
	//判断是否有一行全部相同
	for (int i = 0; i < row; i++)
	{
		if (sameJudge(board, 1, i))
			return board[i][0];
		else
			continue;
	}
	//判断是否有一列全部相同
	for (int j = 0; j < col; j++)
	{
		if (sameJudge(board, 0, j))
			return board[0][j];
		else
			continue;
	}
	//判断+对角线是否相同
	for (int i = 1; i < col; i++)
	{
		if (board[i - 1][i - 1] == board[i][i] && board[i][i] != ' ')
			continue;
		else
			goto turn;
	}
	return board[0][0];
turn:
	//判断-对角线是否相同
	for (int i = 1; i < row; i++)
	{
		if (board[i - 1][col - i] == board[i][col - 1 - i] && board[i][col - 1 - i] != ' ')
			continue;
		else
			goto turn1;
	}
	return board[0][col - 1];
turn1:
	//判断是平局还是继续
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 'C';
		}
	}
	return 'w';
}
