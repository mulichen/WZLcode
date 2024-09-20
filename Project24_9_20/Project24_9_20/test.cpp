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
//常用拷贝函数: copy
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
//常用替换函数: replace,replace_if(条件)将旧元素替换为新元素
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
//常用排序算法，sort，排序，默认从小到大

//常用排序算法
//random_shuffle,洗牌，打乱顺序
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
//常用排序算法
//merge,把两个有序的容器，合并到新的容器中，新容器仍有序
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