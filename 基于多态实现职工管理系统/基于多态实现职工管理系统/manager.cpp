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
	cout << "ְ�����:" << this->m_ID
		<< "       ְ������:" << this->m_name
		<< "       ��λ:" << getDeptname()
		<< "       ְ��ְ��:����ϰ彻��������" << endl;
}
string Manager::getDeptname()
{
	return (string)"����";
}