#define  _CRT_SECURE_NO_WARNINGS
#include "contact.h"
void Jsuo()
{
	printf("********************************\n");
	printf("**** 1.add       2.del     *****\n");
	printf("**** 3.search    4.modify  *****\n");
	printf("**** 5.show      6.sort    *****\n");
	printf("**** 0.exit                *****\n");
	printf("********************************\n");
}
int main()
{
	int iput = 0;
	contact con;
	Jsuo();
	initcontact(&con);
	do
	{
		printf("��ѡ��\n");
		scanf("%d", &iput);
		switch(iput)
		{
		    case 1:
				addcontact(&con);
			    break;
			case 2:
				delcontact(&con);
				break;
			case 3:
				seacontact(&con);
				break;
			case 4:
				modcontact(&con);
				break;
			case 5:
				showcontact(&con);
				break;
			case 6:
				sortcontact(&con);
				break;
			case 0:
				printf("�˳��ɹ�\n");
				break;
			default:
				printf("ѡ���������������\n");
				break;
		}
	}
	while (iput);
}