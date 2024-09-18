#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<algorithm>
#include<functional>
#include<vector>

void test()
{
	vector<bool>v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);
	//sort(v.begin(),v.end(),greater<bool>());
	vector<bool>v1;
	v1.resize(v.size());
	transform(v.begin(), v.end(), v1.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}