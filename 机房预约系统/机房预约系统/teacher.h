#pragma once
#include"Identity.h"
class Teacher : public Identity
{
public:
	Teacher();
	Teacher(int ID, string name, string pwd);
	~Teacher();
	//菜单
	virtual void opermenu();

	//查看全部预约
	void shoeAllOrder();

	//审核预约
	void validOrder();

	//教师编号
	int m_Id;
};