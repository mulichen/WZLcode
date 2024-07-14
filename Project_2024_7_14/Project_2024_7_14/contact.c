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

