#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

//1.常用遍历算法for_each,
class DY
{
public:
	void operator()(int a)
	{
		cout << a << " ";
	}
};
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(),v.end(),DY());
	cout << endl;
}
//2.常用遍历算法transform,
class thansform
{
public:
	int operator()(int a)
	{
		return a;
	}
};
void test02()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>ve;
	ve.resize(v.size());
	transform(v.begin(), v.end(), ve.begin(), thansform());
	for_each(v.begin(), v.end(), DY());
}

//2.常用查找算法find,find_if，adjacent_find(查找相邻相同元素，返回第一个的迭代器)
class person
{
public:
	person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	bool operator==(const person val)
	{
		return this->m_age == val.m_age;
	}
	string m_name;
	int m_age;
};
void test03()
{
	vector<person>v;
	person p1("刘备", 30);
	person p2("关羽", 30);
	person p3("张飞", 30);
	person p4("曹操", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	person p5("诸葛亮", 30);
	vector<person>::iterator it= find(v.begin(),v.end(),p5);
	cout << it->m_name << " " << it->m_age << endl;
	//vector<person>::iterator it = find_if(v.begin(), v.end(), p5);==重置为按条件的
	/*it=adjacent_find(v.begin(), v.end());
	cout << it->m_name << " " << it->m_age << endl;*/
}
//二分查找(必须排好序)
void test04()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	bool a = binary_search(v.begin(), v.end(), 5);
	if (a == 0)
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "已找到" << endl;
	}
}
int main()
{
	//test01();
	//test02();
	//test03();
	test04();
	system("pause");
	return 0;
}
