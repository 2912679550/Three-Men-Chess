#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu()
{
	printf("********************************************************\n");
	printf("******************** 1.paly  0.exit ********************\n");
	printf("********************************************************\n");
	printf("请玩家输入棋子坐标，如第一行第二个位置，则输入1（空格）2\n");

}
//游戏的算法实现
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	IntBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board,ROW,COL);
	while (1)
	{
		//玩家下棋
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}

		//电脑下棋
		computerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//判断电脑是否赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	switch (ret)
	{
	case '*':
		printf("玩家赢\n");
		break;
	case '#':
		printf("电脑赢\n");
		break;
	default:
		printf("平局\n");
		break;
	}

}
void  test() 
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			printf("三字棋\n");
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择");
			break;

		}

	} while (input);

}
int main()
{
	test();
	return 0;
}