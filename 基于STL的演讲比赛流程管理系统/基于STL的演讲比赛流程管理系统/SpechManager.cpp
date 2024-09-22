#define  _CRT_SECURE_NO_WARNINGS
#include"SpechManager.h"
#include"speaker.h"
#include<algorithm>
SpechManager::SpechManager()
{
	initspeach();
	createspech();

}

SpechManager::~SpechManager()
{

}
void SpechManager::shoe_menu()
{
	cout << "******************************************" << endl;
	cout << "************ 欢迎参加演讲比赛 ************" << endl;
	cout << "************  1.开始演讲比赛  ************" << endl;
	cout << "************  2.查看往届记录  ************" << endl;
	cout << "************  3.清空比赛记录  ************" << endl;
	cout << "************  0.退出比赛程序  ************" << endl;
	cout << "******************************************" << endl;
	cout << endl;
}
void SpechManager::initspeach()
{
	this->F.clear();
	this->T.clear();
	this->V.clear();
	this->M.clear();
	this->m_Index = 1;
}
void SpechManager::createspech()
{
	string n = "ABCDEFGHIJKL";
	for (int i = 0; i < 12; i++)
	{
		string name = "姓名";
		name +=n[i];
		speaker sp;
		for (int j = 0; j < 2; j++)
		{
			sp.m_score[j] = 0;
		}
		sp.m_name = name;
		this->F.push_back(1001 + i);
		   this->M.insert(make_pair(1001 + i, sp));
	}
}
void SpechManager::spechdraw()
{
	cout << "第<<" << this->m_Index << ">>轮比赛抽签结果：" << endl;
	if (this->m_Index == 1)
	{
		random_shuffle(F.begin(), F.end());
		for (vector<int>::iterator it = F.begin(); it != F.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(T.begin(), T.end());
		for (vector<int>::iterator it = T.begin(); it != T.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
}
void SpechManager::spechcontest()
{
	cout << "第<<" << this->m_Index << ">>轮比赛开始：" << endl;
	multimap<double, int, greater<double>>groupscore;
	int num = 0;
	vector<int>v;
	if (this->m_Index == 1)
	{
		v = this->F;
	}
	else
	{
		v = this->T;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		num++;
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double s = (rand() % 401 + 600) / 10.f;
			d.push_back(s);
		}
		sort(d.begin(),d.end(),greater<double>());
		d.pop_front();
		d.pop_back();
		double q = accumulate(d.begin(), d.end(), 0.0f);
		double N = q/ (double)d.size();
		groupscore.insert(make_pair(N, *it));
		this->M[*it].m_score[this->m_Index - 1] = N;
		if (num % 6 == 0)
		{
			cout << "第<<" <<num/6<< ">>小组比赛结果：" << endl;
			for (multimap<double, int, greater<double>>::iterator it1 = groupscore.begin(); it1 != groupscore.end(); it1++)
			{
				cout << "编号：" << it1->second << "姓名：" << this->M[it1->second].m_name << "分数：" << this->M[it1->second].m_score[this->m_Index - 1] << endl;
			}
				int count = 0;
				for (multimap<double, int, greater<double>>::iterator it = groupscore.begin(); it != groupscore.end() && count < 3; it++, count++)
				{
					if (this->m_Index == 1)
					{
						this->T.push_back(it->second);
					}
					else
					{
						this->V.push_back(it->second);
					}
				}
				groupscore.clear();
			}

	}
	cout << "第<<" << this->m_Index << ">>轮比赛结束" << endl;
	system("pause");
}
void SpechManager::showscore()
{
	vector<int>v;
	if (this->m_Index == 1)
	{
		v = this->T;
	}
	else
	{
		v = this->V;
	}
	cout << "第<<" << this->m_Index << ">>轮晋级名单：" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "编号：" << *it<< "姓名：" << this->M[*it].m_name << "分数：" << this->M[*it].m_score[this->m_Index - 1] << endl;
	}
	system("pause");
}
void SpechManager::stackspech()
{
	spechdraw();
	spechcontest();
	showscore();
	this->m_Index++;
	spechdraw();
	spechcontest();
	showscore();
}