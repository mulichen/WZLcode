#pragma once
#include<stdio.h>
#include<string.h>

//��������
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
//�����ϵ��
void addcontact(contact* con);
void initcontact(contact* con);
void delcontact(contact* con);



