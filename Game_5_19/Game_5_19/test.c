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
		printf("ѡ��Ӯ\n");
	}
	else if (wzl == '#')
	{
		printf("����Ӯ\n");
	}
	else if(wzl='q')
	{
		printf("ƽ��\n");
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
		printf("��ѡ��>\n");
		scanf("%d",&iput);
		switch (iput)
		{
		case 1:
			printf("������\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������\n");
			break;
		}

	}
	while (iput);
	return 0;
}