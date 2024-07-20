#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

//类型声明
typedef struct peoinfo
{
	char name[20];
	int age;
	char sex[10];
	char tele[12];
	char addr[30];
}peoinfo;
typedef struct contact
{
	peoinfo data[100];
	int count;
}contact;
//添加联系人
void addcontact(contact* con);
void initcontact(contact* con);
void delcontact(contact* con);
void seacontact(contact* con);
void modcontact(contact* con);
void showcontact(contact* con);
void sortcontact(contact* con);
void read(contact* con);
void write(contact* con);








