#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
void myprint(int val)
{
	cout << val << " ";
}
//交集
void test01()
{
	vector<int>v;
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		v1.push_back(i + 5);
	}
	vector<int>v2;
	v2.resize(min(v.size(), v1.size())); 
	vector<int>::iterator it = set_intersection(v.begin(), v.end(), v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(), it, myprint);
	cout << endl;
}
//并集
void test02()
{
	vector<int>v;
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		v1.push_back(i + 5);
	}
	vector<int>v2;
	v2.resize(v.size()+ v1.size());
	vector<int>::iterator it = set_union(v.begin(), v.end(), v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(), it, myprint);
	cout << endl;
}
//差集
void test03()
{
	vector<int>v;
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		v1.push_back(i + 5);
	}
	vector<int>v2;
	vector<int>v3;
	v2.resize(max(v.size(),v1.size()));
	vector<int>::iterator it = set_difference(v.begin(), v.end(), v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(), it, myprint);
	cout << endl;
	v3.resize(max(v.size(), v1.size()));
	it = set_difference(v1.begin(), v1.end(), v.begin(), v.end(), v3.begin());
	for_each(v3.begin(), it, myprint);
	cout << endl;
}
int main()
{
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}