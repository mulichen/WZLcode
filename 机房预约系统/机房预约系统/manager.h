#pragma once
#include"Identity.h"
#include"globallfile.h"
#include<fstream>
#include"student.h"
#include"teacher.h"
#include<vector>
#include"computer.h"
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

	//��ʼ������
	void intvector();

	//ѧ������
	vector<Student>vs;

	//��ʦ����
	vector<Teacher>vt;

	//��������
	vector<Computer>vc;

	//�ж��ظ�
	bool checkrepeat(string id, int pty);
};