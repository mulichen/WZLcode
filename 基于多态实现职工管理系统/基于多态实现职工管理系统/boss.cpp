#define  _CRT_SECURE_NO_WARNINGS
#include"boss.h"
Boss::Boss(int ID, string name, int D_ID)
{
	this->m_ID = ID;
	this->m_name = name;
	this->m_DeptID = D_ID;
}
void Boss::showInfo()
{
	cout << "职工编号:" << this->m_ID
		<< "       职工姓名:" << this->m_name
		<< "       岗位:" << getDeptname()
		<< "       职工职责:管理公司所有事务" << endl;
}
string Boss::getDeptname()
{
	return (string)"总裁";
}