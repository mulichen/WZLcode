#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
using namespace std;
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
void test()
{
	vector<person>v;
	person p1("a", 18);
	person p2("b", 18);
	person p3("c", 18);
	person p4("d", 18);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	for (vector<person>::iterator it = v.begin(); it < v.end(); it++)
	{
		cout << "姓名: " << (*it).m_name << "年龄: " << (*it).m_age << endl;
	}

}
void test01()
{
	vector<person*>v;
	person p1("a", 18);
	person p2("b", 18);
	person p3("c", 18);
	person p4("d", 18);
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	for (vector<person*>::iterator it = v.begin(); it < v.end(); it++)
	{
		cout << "::姓名: " << (*it)->m_name << "年龄: " << (*it)->m_age << endl;
	}
}
int main()
{

	test();
	test01();

}