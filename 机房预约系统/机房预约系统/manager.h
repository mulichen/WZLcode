#pragma once
#include"Identity.h"
#include"globallfile.h"
#include<fstream>
class Manager:public Identity
{
public:
	Manager();
	Manager(string name, string pwd);
	~Manager();
	//�˵�
	virtual void opermenu();

	//����˺�
	void AddPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showC();

	//���ԤԼ��¼
	void clearFile();

};