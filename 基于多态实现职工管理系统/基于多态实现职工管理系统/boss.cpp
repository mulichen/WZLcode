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
	cout << "ְ�����:" << this->m_ID
		<< "       ְ������:" << this->m_name
		<< "       ��λ:" << getDeptname()
		<< "       ְ��ְ��:����˾��������" << endl;
}
string Boss::getDeptname()
{
	return (string)"�ܲ�";
}