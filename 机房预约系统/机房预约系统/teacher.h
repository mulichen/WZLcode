#pragma once
#include"Identity.h"
class Teacher : public Identity
{
public:
	Teacher();
	Teacher(string ID, string name, string pwd);
	~Teacher();
	//�˵�
	virtual void opermenu();

	//�鿴ȫ��ԤԼ
	void shoeAllOrder();

	//���ԤԼ
	void validOrder();

	//��ʦ���
	string m_Id;
};