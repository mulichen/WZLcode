#pragma once
#include"Identity.h"
#include<vector>
#include"computer.h"
#include"globallfile.h"
#include<fstream>
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

	//ȡ��ԤԼ
	void cancelOrder();

	//��������
	vector<Computer>vc;


	//ѧ��ѧ��
	int m_Id;
};