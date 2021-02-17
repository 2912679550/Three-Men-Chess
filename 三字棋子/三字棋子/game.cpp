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
		//��ӡһ������
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
			else
				printf("\n");
		}
		//printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
		//��ӡ���з���
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
	printf("�����:>\t");
	while (1)
	{
		printf("������Ҫ�µ�����:>");
		scanf("%d%d", &x, &y);
		//�ж�����Ϸ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y-1] == ' ')
			{
				board[x - 1][y - 1] = '*';
			
				break;
			}
			else
			{
				printf("������㱻ռ��\n");
			}
		}
		else {
			printf("����Ƿ�������������\n");
		}
	}
}

void computerMove(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("������\n");
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


int sameJudge(char board[ROW][COL], int row_col, int num)//��Ϊ1 ����Ϊ0
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
	//�ж��Ƿ���һ��ȫ����ͬ
	for (int i = 0; i < row; i++)
	{
		if (sameJudge(board, 1, i))
			return board[i][0];
		else
			continue;
	}
	//�ж��Ƿ���һ��ȫ����ͬ
	for (int j = 0; j < col; j++)
	{
		if (sameJudge(board, 0, j))
			return board[0][j];
		else
			continue;
	}
	//�ж�+�Խ����Ƿ���ͬ
	for (int i = 1; i < col; i++)
	{
		if (board[i - 1][i - 1] == board[i][i] && board[i][i] != ' ')
			continue;
		else
			goto turn;
	}
	return board[0][0];
turn:
	//�ж�-�Խ����Ƿ���ͬ
	for (int i = 1; i < row; i++)
	{
		if (board[i - 1][col - i] == board[i][col - 1 - i] && board[i][col - 1 - i] != ' ')
			continue;
		else
			goto turn1;
	}
	return board[0][col - 1];
turn1:
	//�ж���ƽ�ֻ��Ǽ���
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
