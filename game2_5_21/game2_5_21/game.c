#define  _CRT_SECURE_NO_WARNINGS
#include "game.h"
void G_shu(char board[HANS][LIES], int han, int lie,char ch)
{
	int i = 0;
	for (i=0;i<han;i++)
	{
		int j = 0;
		for (j = 0; j < lie; j++)
		{
			board[i][j] = ch;
		}

	}
}
void D_shu(char board[HANS][LIES], int han, int lie)
{
	int i = 0;
	int k = 0;
	printf("***扫雷开始***\n");
	for (k = 0; k <= lie; k++)
	{
		printf("%d ", k);
	}
	printf("\n");
	for (i = 1; i <= han; i++)
	{
		int j = 0;
		printf("%d ", i);
		for (j = 1; j <= lie; j++)
		{
			printf("%c",board[i][j]);
			printf(" ");
		}
		printf("\n");
	}
	printf("***扫雷开始***\n");
}
void S_lie(char board[HANS][LIES], int han, int lie)
{
	int shu = NY;
	while (shu)
	{
		int x = rand()%han+1;
		int y = rand()%lie+1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			shu--;
		}
	}
}
int B_li(char mine[HANS][LIES], int x, int y)
{
	return (mine[x-1][y-1]+mine[x-1][y]+ mine[x-1][y+1]
		+ mine[x][y-1]+ mine[x][y+1]+ mine[x+1][y-1]
		+ mine[x+1][y]+ mine[x+1][y-1])-8*'0';
}
void P_lie(char mine[HANS][LIES], char show[HANS][LIES], int han, int lie)
{
	int x = 0;
	int y = 0;
	int num1 = 0;
	 while (num1<han*lie-NY)
	 {
		printf("请输入想排查的坐标\n");
		scanf("%d %d", &x,&y);
		int num = 0;
		if (show[x][y] != '*')
		{
			printf("该坐标已经排查过了，不能重复排查\n");
		}
		else
		{
			if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
			{
				if (mine[x][y] == '0')
				{
				    num1++;
					num = B_li(mine, x, y);
					show[x][y] = num + '0';
					D_shu(show, HAN, LIE);
				}
				else
				{
					printf("很遗憾，你被炸死了\n");
					D_shu(mine, HAN, LIE);
					break;
				}
			}
			else
			{
				printf("输入坐标非法，请重新输入");
			}
		}
	 }
	if (num1 == han * lie - NY)
	{
		printf("恭喜你，全部排查成功\n");
		D_shu(mine, HAN, LIE);
	}
}