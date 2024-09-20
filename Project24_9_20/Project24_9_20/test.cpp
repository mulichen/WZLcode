#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<ctime>
using namespace std;
class myprint
{
	
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
//���ÿ�������: copy
void test()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(40);
	v.push_back(60);
	v.push_back(20);
	vector<int>v1;
	v1.resize(v.size());
	copy(v.begin(),v.end(),v1.begin());
	for_each(v1.begin(), v1.end(), myprint());
	cout << endl;
}
//�����滻����: replace,replace_if(����)����Ԫ���滻Ϊ��Ԫ��
class less30
{
public:
	bool operator()(int val)
	{
		return val < 30;
	}
};
void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(30);
	v.push_back(40);
	v.push_back(30);
	v.push_back(20);
	replace(v.begin(), v.end(), 30, 300);
	replace_if(v.begin(), v.end(),less30(),100);
	for_each(v.begin(), v.end(), myprint());
	cout << endl;
}
//���������㷨��sort������Ĭ�ϴ�С����

//���������㷨
//random_shuffle,ϴ�ƣ�����˳��
void test02()
{
	srand((unsigned int)time(nullptr));
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), myprint());
	cout << endl;
}
//���������㷨
//merge,������������������ϲ����µ������У�������������
void test03()
{
	vector<int>v;
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		v1.push_back(i);
	}
	vector<int>v3;
	v3.resize(v.size() + v1.size());
	merge(v.begin(),v.end(), v1.begin(),v1.end(), v3.begin());
	for_each(v3.begin(), v3.end(), myprint());
	cout << endl;
}
int main()
{
	test();
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}