#define  _CRT_SECURE_NO_WARNINGS
#include"teacher.h"
Teacher::Teacher()
{
	this->m_Id = 0; // ��ʽ��ʼ��Ϊ0
	this->m_name = ""; // �����string���ͣ����Գ�ʼ��Ϊ���ַ���
	this->m_pwd = ""; // ͬ����ʼ������Ϊ���ַ���
}
Teacher::Teacher(int ID, string name, string pwd)
{
	this->m_Id = ID;
	this->m_name = name;
	this->m_pwd = pwd;
}
Teacher::~Teacher()
{

}

//�˵�
void Teacher::opermenu()
{

}

//�鿴ȫ��ԤԼ
void Teacher::shoeAllOrder()
{

}

//���ԤԼ
void Teacher::validOrder()
{

}