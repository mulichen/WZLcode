#pragma once
#include"Identity.h"
class Student: public Identity
{
public:
	Student();
	Student(int ID,string name, string pwd);
	~Student();
	//�˵�
	virtual void opermenu();
	
	//����ԤԼ
	void applyOrder();

	//�鿴�ҵ�ԤԼ
	void showMyOrder();

	//�鿴ȫ��ԤԼ
	void shoeAllOrder();
	//ѧ��ѧ��
	int m_Id;
};