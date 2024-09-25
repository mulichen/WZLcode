#pragma once
#include"Identity.h"
#include"globallfile.h"
#include<fstream>
#include"student.h"
#include"teacher.h"
#include<vector>
class Manager:public Identity
{
public:
	Manager();
	Manager(string name, string pwd);
	~Manager();
	//菜单
	virtual void opermenu();

	//添加账号
	void AddPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showC();

	//清空预约记录
	void clearFile();

	//初始化容器
	void intvector();

	//学生容器
	vector<Student>vs;

	//老师容器
	vector<Teacher>vt;

	//判断重复
	bool checkrepeat(int id, int pty);
};