#pragma once
#include"Identity.h"
#include<vector>
#include"computer.h"
#include"globallfile.h"
#include<fstream>
#include"orderfile.h"
class Student: public Identity
{
public:
	Student();
	Student(string ID,string name, string pwd);
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
	string m_Id;
};