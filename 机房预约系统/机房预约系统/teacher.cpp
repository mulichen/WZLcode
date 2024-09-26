#define  _CRT_SECURE_NO_WARNINGS
#include"teacher.h"
Teacher::Teacher()
{
	this->m_Id = 0; // 显式初始化为0
	this->m_name = ""; // 如果是string类型，可以初始化为空字符串
	this->m_pwd = ""; // 同样初始化密码为空字符串
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

//菜单
void Teacher::opermenu()
{

}

//查看全部预约
void Teacher::shoeAllOrder()
{

}

//审核预约
void Teacher::validOrder()
{

}