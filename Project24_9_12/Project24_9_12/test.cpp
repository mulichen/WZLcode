#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>
void test01()
{
	string str;
	str = "hello";
	char M = str.at(0);//�ַ�����ȡҲ����[]
	cout << M << endl;
	int a= str.find("lo");//�ַ�������,��ǰ����
	cout << a << endl;
	int b = str.rfind("lo");//�Ӻ���ǰ
	cout << b << endl;
	str.replace(0, 3, "wzl");//wzllo
	cout << str << endl;
	//�ַ���ƴ��
	//+=
	str += 'a';
	str += "bcd";
	string st = "efg";
	str += st;
	str.append("a");
	cout << str << endl;
	//str.append
	int w=str.compare(st);
	if (w == 0)
	{
		cout << "=" << endl;
	}
	else if (w < 0)
	{
		cout << "<" << endl;
	}
	else
		cout << ">" << endl;
}
int main()
{
	test01();
}