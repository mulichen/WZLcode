#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<set>
#include<string>
class person
{
public:
	person(string name,int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	string m_name;
	int m_age;
};

class PX
{
public:
	bool operator()(const person &p1,const person &p2)const
	{
		return p1.m_age > p2.m_age;
	}
};
void test01()
{
	set<person,PX>se;
    person p1("刘备", 24);
    person p2("关羽", 28);
	person p3("张飞", 25);
	person p4("赵云", 21);
	se.insert(p1);
	se.insert(p2);
	se.insert(p3);
	se.insert(p4);
	for (set<person, PX>::iterator it = se.begin(); it != se.end(); it++)
	{
		cout << "姓名：" << it->m_name << " " << it->m_age<<endl;
	}
}
int main()
{
	test01();
	system("pause");
	return 0;
}