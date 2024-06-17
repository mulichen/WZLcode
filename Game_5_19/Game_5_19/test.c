#define  _CRT_SECURE_NO_WARNINGS
#include "game.h"
int meun()
{
	printf("********************\n");
	printf("***1.play  0.exit***\n");
	printf("********************\n");
}
int game()
{
	char wzl = 0;
	char board[Han][Lie] = { 0 };
	QiPan(board, Han, Lie);
	D_QiPan(board, Han, Lie);
	while (1)
	{
		playermove(board, Han, Lie);
		wzl = Win(board, Han, Lie);
		if (wzl != 'c')
		{
			break;
		}
		D_QiPan(board, Han, Lie);
		computermove(board, Han, Lie);
		wzl = Win(board, Han, Lie);
		if (wzl != 'c')
		{
			break;
		}
		D_QiPan(board, Han, Lie);
	}
	if (wzl == '*')
	{
		printf("选手赢\n");
	}
	else if (wzl == '#')
	{
		printf("电脑赢\n");
	}
	else if(wzl='q')
	{
		printf("平局\n");
	}
	D_QiPan(board, Han, Lie);
}
int main()
{
	srand((unsigned int)time(0));
	int iput = 0;
	do
	{
		meun();
		printf("请选择>\n");
		scanf("%d",&iput);
		switch (iput)
		{
		case 1:
			printf("三子棋\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}

	}
	while (iput);
	return 0;
}