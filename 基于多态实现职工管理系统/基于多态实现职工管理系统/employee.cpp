#define  _CRT_SECURE_NO_WARNINGS
#include"employee.h"
Employee::Employee(int ID, string name, int D_ID)
{
	this->m_ID = ID;
	this->m_name = name;
	this->m_DeptID = D_ID;
}
void Employee::showInfo()
{
	cout << "ְ�����:" << this->m_ID
		<< "       ְ������:" << this->m_name
		<< "       ��λ:" << getDeptname()
		<< "       ְ��ְ��:��ɾ�����������" << endl;
}
string Employee::getDeptname()
{
	return (string)"Ա��";
}