#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<numeric>
#include<vector>
#include<algorithm>
class myprint
{
public:
	void operator()(int val)
	{
		cout << val<< " ";
	}
};
//¼ÆËãÈÝÆ÷ÔªËØÀÛ¼ÆºÍ£ºaccumulate
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	int a=accumulate(v.begin(),v.end(),0);
	//for_each(v.begin(), v.end(), myprint());
	cout <<a<< endl;
}
//ÏòÈÝÆ÷Ìî³äÔªËØ
void test02()
{
	vector<int>v;
	v.resize(10);
	fill(v.begin(), v.end(), 100);
	for_each(v.begin(), v.end(), myprint());
	cout << endl;
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}