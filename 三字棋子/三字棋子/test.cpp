#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu()
{
	printf("********************************************************\n");
	printf("******************** 1.paly  0.exit ********************\n");
	printf("********************************************************\n");
	printf("����������������꣬���һ�еڶ���λ�ã�������1���ո�2\n");

}
//��Ϸ���㷨ʵ��
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	//��ʼ������
	IntBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board,ROW,COL);
	while (1)
	{
		//�������
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}

		//��������
		computerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	switch (ret)
	{
	case '*':
		printf("���Ӯ\n");
		break;
	case '#':
		printf("����Ӯ\n");
		break;
	default:
		printf("ƽ��\n");
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
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			printf("������\n");
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��");
			break;

		}

	} while (input);

}
int main()
{
	test();
	return 0;
}