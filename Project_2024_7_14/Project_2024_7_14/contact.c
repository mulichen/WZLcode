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
		printf("通讯录已满，无法添加\n");
		return;
	}
	else
	{
		printf("请输入添加人信息\n");
		printf("姓名，年龄，性别，电话，地址\n");
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
		printf("为空，没有信息删除");
		return;
	}
	else
	{
		printf("请输入删除人姓名");
		scanf("%s", &mame);
		int c=cha(con, mame);
		if (c == -1)
		{
			printf("查无此人");
		}
		else
		{
			for (int i = c; i < con->count-1; i++)
			{
				con->data[i] = con->data[i + 1];
			}
			con->count--;
			printf("删除成功\n");
		}
	}
	
}
void seacontact(contact* con)
{
	char m[20] = { 0 };
	printf("请输入要搜索的姓名:");
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
			printf("没有查找到此人信息\n");
	}
}
void modcontact(contact* con)
{
	char m[20] = { 0 };
	printf("请输入要修改的人的姓名:");
	scanf("%s", &m);
	for (int i = 0; i < con->count; i++)
	{
		if (0 == strcmp(con->data[i].name, m))
		{
			printf("已查找到，请重新输入添加人信息\n");
			printf("姓名，年龄，性别，电话，地址\n");
			scanf("%s", con->data[i].name);
			scanf("%d", &(con->data[i].age));
			scanf("%s", con->data[i].sex);
			scanf("%s", con->data[i].tele);
			scanf("%s", con->data[i].addr);
			printf("修改完成\n");
		}
		else
			printf("没有查找到此人信息\n");
	}
}
void showcontact(contact* con)
{
	if (con->count == 0)
	{
		printf("为空，没有信息\n");
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
	printf("排序成功\n");
}






