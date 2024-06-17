#define  _CRT_SECURE_NO_WARNINGS
#include "game.h"

void QiPan(char board[Han][Lie], int han, int lie)
{
	int i = 0;
	for (i = 0; i < han; i++)
	{
		int j = 0;
		for (j = 0; j < lie; j++)
		{
			board[i][j] = ' ';
		}
	}

}
void D_QiPan(char board[Han][Lie], int han, int lie)
{
	int i = 0;
	for (i = 0; i < han; i++)
	{
		int j = 0;
		for (j = 0; j < lie; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < lie-1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < han - 1)
		{
			int j = 0;
			for(j=0;j<lie;j++)
			{
				printf("---");

				if (j < lie - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}

	}
}
//选手下棋
void playermove(char board[Han][Lie], int han, int lie)
{
	int x = 0;
	int y = 0;
	printf("玩家下棋\n");
	while (1)
	{
		printf("请输入坐标>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= lie && y>=1 && y <= han)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("坐标被占用，请重新输入\n");
		}
		else
			printf("坐标非法，请重新输入\n");
	}
}
//电脑下棋
void computermove(char board[Han][Lie], int han, int lie)
{
	printf("电脑下棋\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % han;
		y = rand() % lie;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
int IsFull(char board[Han][Lie], int han, int lie)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < han; i++)
	{
		for (j = 0; j < lie; j++)
		{
			if (board[i][j] != ' ');
			return 0;
		}
	}
	return 1;
}
int Win(char board[Han][Lie], int han, int lie)
{
	int x = 0;
	int y = 0;
	//行
	for (x = 0; x < han; x++)
	{
		if (board[x][0] == board[x][1] && board[x][1] == board[x][2]&&board[x][0] != ' ')
		{
			return board[x][0];
		}
	}
	for (y = 0; y < han; y++)
	{
		if (board[0][y] == board[1][y] && board[1][y] == board[2][y]&& board[0][y]!=' ')
		{
			return board[0][y];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
		return board[0][0];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
	{
		return board[0][2];
	}
	if (IsFull(board, Han, Lie))
	{
		return 'q';
	}
	return 'c';
}

