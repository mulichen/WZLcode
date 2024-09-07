#pragma once
#include<iostream>
using namespace std;
#include<string>
class worker
{
public:
	virtual void showInfo() = 0;
	virtual string getDeptname() = 0;
//private:
	int m_ID;
	string m_name;
	int m_DeptID;
};