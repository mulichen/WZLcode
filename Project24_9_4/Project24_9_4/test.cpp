#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<fstream>
#include<string>
void test()
{
	ofstream ofs;
	ofs.open("test.txt", ios::out);
	ofs << "����:����" << endl;
	ofs << "����:18" << endl;
	ofs.close();
}
void test1()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	string num;
	while (getline(ifs, num))
	{
		cout << num << endl;
	}
}
int main()
{
	//test();
	test1();
	return 0;
}