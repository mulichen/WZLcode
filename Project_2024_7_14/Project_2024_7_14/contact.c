#define  _CRT_SECURE_NO_WARNINGS
#include "contact.h"
void initcontact(contact* con)
{
	con->count = 0;
	memset(con->data,0,sizeof(con->data));
}
void addcontact(contact* con)
{
	if (con->count == 100)
	{
		printf("ͨѶ¼�������޷����\n");
		return;
	}
	else
	{
		printf("�������������Ϣ\n");
		printf("���������䣬�Ա𣬵绰����ַ\n");
		scanf("%s", con->data[con->count].name);
		scanf("%d", &(con->data[con->count].age));
		scanf("%s", con->data[con->count].sex);
		scanf("%s", con->data[con->count].tele);
		scanf("%s", con->data[con->count].addr);
		con->count++;
	}
}
int cha(contact* con,char mame[])
{
	int i = 0;
	for (i = 0; i < con->count; i++)
	{
		if (0==strcmp(con->data[i].name, mame))
		{return i;}
	}
	return -1;
}
void delcontact(contact* con)
{
	char mame[20] = { 0 };
	if (con->count == 0)
	{
		printf("Ϊ�գ�û����Ϣɾ��");
		return;
	}
	else
	{
		printf("������ɾ��������");
		scanf("%s", &mame);
		int c=cha(con, mame);
		if (c == -1)
		{
			printf("���޴���");
		}
		else
		{
			for (int i = c; i < con->count-1; i++)
			{
				con->data[i] = con->data[i + 1];
			}
			con->count--;
			printf("ɾ���ɹ�\n");
		}
	}
	
}
void seacontact(contact* con)
{
	char m[20] = { 0 };
	printf("������Ҫ����������:");
	scanf("%s",&m);
	for (int i = 0; i < con->count; i++)
	{
		if (0 == strcmp(con->data[i].name, m))
		{
			printf("%s,%d,%s,%s,%s\n", con->data[i].name,
				                       con->data[i].age,
				                       con->data[i].sex,
				                       con->data[i].tele,
				                       con->data[i].addr);
		}
		else
			printf("û�в��ҵ�������Ϣ\n");
	}
}
void modcontact(contact* con)
{
	char m[20] = { 0 };
	printf("������Ҫ�޸ĵ��˵�����:");
	scanf("%s", &m);
	for (int i = 0; i < con->count; i++)
	{
		if (0 == strcmp(con->data[i].name, m))
		{
			printf("�Ѳ��ҵ��������������������Ϣ\n");
			printf("���������䣬�Ա𣬵绰����ַ\n");
			scanf("%s", con->data[i].name);
			scanf("%d", &(con->data[i].age));
			scanf("%s", con->data[i].sex);
			scanf("%s", con->data[i].tele);
			scanf("%s", con->data[i].addr);
			printf("�޸����\n");
		}
		else
			printf("û�в��ҵ�������Ϣ\n");
	}
}
void showcontact(contact* con)
{
	if (con->count == 0)
	{
		printf("Ϊ�գ�û����Ϣ\n");
		return;
	}
	else
	{
		for (int i = 0; i < con->count; i++)
		{
			printf("%s,%d,%s,%s,%s\n", con->data[i].name,
				con->data[i].age,
				con->data[i].sex,
				con->data[i].tele,
				con->data[i].addr);
		}
	}
}
int compare(const void* a, const void* b)
{
	return(strcmp(((peoinfo*)a)->name, ((peoinfo*)b)->name));
}
void sortcontact(contact* con)
{
	qsort(con->data, con->count, sizeof(peoinfo), compare);
	printf("����ɹ�\n");
}






