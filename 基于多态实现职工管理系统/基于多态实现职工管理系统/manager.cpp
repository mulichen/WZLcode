#define  _CRT_SECURE_NO_WARNINGS
#include"manager.h"
Manager::Manager(int ID, string name, int D_ID)
{
	this->m_ID = ID;
	this->m_name = name;
	this->m_DeptID = D_ID;
}
void Manager::showInfo()
{
	cout << "职工编号:" << this->m_ID
		<< "       职工姓名:" << this->m_name
		<< "       岗位:" << getDeptname()
		<< "       职工职责:完成老板交给的任务" << endl;
}
string Manager::getDeptname()
{
	return (string)"经理";
}