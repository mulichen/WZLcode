#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
void myd(vector<int>& v)
{
	/*for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it<<" ";
	}*///或
	for (int i = 0; i < v.size(); i++)
	{
		//cout << v[i] << " ";或
		cout << v.at(i)<<" ";
	}
	cout << endl;
}
void test()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}


	vector<int>v1;
	//vector的赋值操作
	//v1 = v;
	v1.assign(v.begin(), v.end());

	myd(v);
	myd(v1);
}
//互换容器
void test01()
{
	vector<int>v;
	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
	}
	v.resize(3);
	cout << "容量：" << v.capacity() << endl;
	cout << "大小：" << v.size() << endl;
	vector<int>(v).swap(v);//匿名拷贝构造函数，会根据大小而制定容量
	cout << "容量：" << v.capacity() << endl;
	cout << "大小：" << v.size() << endl;
}
//预留空间,当知道数据量较大时可以用reserve预留空间
//void test02()
//{
//	vector<int>v;
//	int *p=nullptr;
//	int b = 0;
//	//v.reserve(10000);
//	for (int i = 0; i < 10000; i++)
//	{
//		v.push_back(i);
//		if (p != &v[0])//知道开辟了多少次空间
//		{
//			p = &v[0];
//			b++;
//		}
//	}
//	cout << b << endl;//
//}
//
void test03()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	v.pop_back();//尾删
	myd(v);
	v.insert(v.begin()+1, 100);
	myd(v);
	v.insert(v.begin() + 1,3,100);
	myd(v);
	v.erase(v.begin(), v.end() - 1);
	myd(v);
	v.clear();
	myd(v);
}
int main()
{
	//test();
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}