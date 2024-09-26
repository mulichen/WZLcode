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
	//菜单
	virtual void opermenu();
	
	//申请预约
	void applyOrder();

	//查看我的预约
	void showMyOrder();

	//查看全部预约
	void shoeAllOrder();

	//取消预约
	void cancelOrder();

	//机房容器
	vector<Computer>vc;


	//学生学号
	int m_Id;
};