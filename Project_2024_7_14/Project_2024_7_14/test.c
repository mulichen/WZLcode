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

	do
	{
		printf("��ѡ��\n");
		scanf("%d", &iput);
		switch(iput)
		{
		    case 1:
				initcontact(&con);
				addcontact(&con);
			    break;
			case 2:
				delcontact(&con);
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:

				break;
			case 6:
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