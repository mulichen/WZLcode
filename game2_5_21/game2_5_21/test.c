#define  _CRT_SECURE_NO_WARNINGS
#include "game.h"
void Jmian()
{
	printf("**********************\n");
	printf("**** 1. ɨ����Ϸ  ****\n");
	printf("**** 2. �˳���Ϸ  ****\n");
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
		printf("������\n");
		scanf("%d",&input);
		switch(input)
		{
		case 1:
			printf("��Ϸ��ʼ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������\n");
			break;
		}
	} while (input);
	return 0;
}