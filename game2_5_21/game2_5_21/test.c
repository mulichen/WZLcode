#define  _CRT_SECURE_NO_WARNINGS
#include "game.h"
void Jmian()
{
	printf("**********************\n");
	printf("**** 1. 扫雷游戏  ****\n");
	printf("**** 2. 退出游戏  ****\n");
	printf("**********************\n");
}
void game()
{
	char mine[HANS][LIES] = {0};
	char show[HANS][LIES] = {0};
	G_shu(mine,HANS,LIES,'0');
	G_shu(show,HANS,LIES,'*');
	S_lie(mine, HAN, LIE);
	//D_shu(mine,HAN,LIE);
	D_shu(show,HAN,LIE);
	P_lie(mine,show,HAN,LIE);
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		Jmian();
		printf("请输入\n");
		scanf("%d",&input);
		switch(input)
		{
		case 1:
			printf("游戏开始\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (input);
	return 0;
}