#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<map>
#include<ctime>
class worker
{
public:
	worker(string name, int salary)
	{
		this->m_name = name;
		this->m_salary = salary;
	}
	string m_name;
	int m_salary;
};
void Cworker(vector<worker>&v)
{
	string n = "ABCDEGFHIJ";
	for (int i = 0; i < 10; i++)
	{
		string name = "Ա��";
		name += n[i];
		int salary = rand() % 10000 + 10000;
		v.push_back(worker(name, salary));
	}
}
void SetGroup(vector<worker>&v, multimap<int, worker>&m)
{
	for (vector<worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		int temp = rand() % 3;
		m.insert(pair<int, worker>(temp, *it));
	}
}
void ShowWorker(multimap<int, worker>& m)
{
	int p = m.count(0);
	map<int, worker>::iterator it = m.find(0);
	cout << "�߻����ţ�" << endl;
	for (int num = 0; it != m.end() && num < p; it++, num++)
	{
		cout << "������" << it->second.m_name << "���ʣ�" << it->second.m_salary << endl;
	}
	cout << "----------------------------" << endl;

	cout << "�������ţ�" << endl;
	p = m.count(1);
	it = m.find(1);

	for (int num = 0; it != m.end() && num < p; it++, num++)
	{
		cout << "������" << it->second.m_name << "���ʣ�" << it->second.m_salary << endl;
	}
	cout << "----------------------------" << endl;

	cout << "�з����ţ�" << endl;
	p = m.count(2);
	it = m.find(2);

	for (int num = 0; it != m.end() && num < p; it++, num++)
	{
		cout << "������" << it->second.m_name << "���ʣ�" << it->second.m_salary << endl;
	}
}
void test()
{
	srand((unsigned int)time(nullptr));
	vector<worker>v;
	Cworker(v);
	//for (vector<worker>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << "������" << it->m_name << "���ʣ�" << it->m_salary << endl;
	//}
	multimap<int, worker>m;
	SetGroup(v,m);
	//for (map<int ,worker>::iterator it = m.begin(); it != m.end(); it++)
	//{
	//	cout << "������" << it->second.m_name << "���ʣ�" << it->second.m_salary << endl;
	//}
	ShowWorker(m);
}
int main()
{
	test();
	system("pause");
	return 0;
}