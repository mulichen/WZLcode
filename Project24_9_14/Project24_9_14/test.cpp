#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
#include<ctime>
class person
{
public:
	person(string name, int score)
	{
		this->m_name = name;
		this->m_score = score;
	}
	string m_name;
	int m_score;
};
void TP(vector<person>&v)
{
	string M = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += M[i];
		int score = 0;
		person p(name, score);
		v.push_back(p);
	}
}
void setscore(vector<person>&v)
{
	srand((unsigned int)time(nullptr));
	for (vector<person>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int>D;
		for (int i = 0; i < 10; i++)
		{
			int b = rand() % 40 + 60;
			D.push_back(b);
		}
		sort(D.begin(),D.end());
		D.pop_back();
		D.pop_front();
		int temp = 0;
		for (deque<int>::iterator it1 = D.begin(); it1 != D.end(); it1++)
		{
			temp+= *it1;
		}
		int score = temp / D.size();
		it->m_score = score;
	} 
}
void DY(vector<person>& v)
{
	for (vector<person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "选手：" << it->m_name <<" " << "平均分：" << it->m_score << endl;
	}
}
void test01()
{
	vector<person>v;
	TP(v);
	setscore(v);
	DY(v);
}
int main()
{
	test01();
	system("pause");
	return 0;
}