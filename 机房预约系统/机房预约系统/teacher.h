#pragma once
#include"Identity.h"
class Teacher : public Identity
{
public:
	Teacher();
	Teacher(int ID, string name, string pwd);
	~Teacher();
	//�˵�
	virtual void opermenu();

	//�鿴ȫ��ԤԼ
	void shoeAllOrder();

	//���ԤԼ
	void validOrder();

	//��ʦ���
	int m_Id;
};