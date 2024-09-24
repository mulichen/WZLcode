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

};