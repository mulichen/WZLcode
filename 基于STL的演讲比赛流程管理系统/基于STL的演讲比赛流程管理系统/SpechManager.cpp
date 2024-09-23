#define  _CRT_SECURE_NO_WARNINGS
#include"SpechManager.h"
#include"speaker.h"
#include<algorithm>
SpechManager::SpechManager()
{
	initspeach();
	createspech();
	loadrecord();

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
	this->Mrcord.clear();
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
	cout << "      第<<" << this->m_Index << ">>轮比赛抽签结果：" << endl;
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
	srand((unsigned int)time(nullptr));
	cout << "      第<<" << this->m_Index << ">>轮比赛开始：" << endl;
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
			cout << "      第<<" <<num/6<< ">>小组比赛结果：" << endl;
			for (multimap<double, int, greater<double>>::iterator it1 = groupscore.begin(); it1 != groupscore.end(); it1++)
			{
				cout << "编号：" << it1->second << "姓名：" << this->M[it1->second].m_name << "分数：" << this->M[it1->second].m_score[this->m_Index - 1] << endl;
			}
			cout <<endl;
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
	cout << "      第<<" << this->m_Index << ">>轮比赛结束" << endl;
	cout << endl;
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
	cout << "      第<<" << this->m_Index << ">>轮晋级名单：" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "编号：" << *it<< "姓名：" << this->M[*it].m_name << "分数：" << this->M[*it].m_score[this->m_Index - 1] << endl;
	}
	system("pause");
}
void SpechManager::savescore()
{
	ofstream ofs;
	ofs.open("往届比赛.csv", ios::out | ios::app);
	for (vector<int>::iterator it = V.begin(); it != V.end(); it++)
	{
		ofs<<*it<<","<< this->M[*it].m_score[1]<<",";
	}
	ofs << endl;
	ofs.close();
	cout << "保存完毕" << endl;
	this->FIE = false;
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
	savescore();
	initspeach();
	createspech();
	loadrecord();
}
void SpechManager::loadrecord()
{
	string data;
	int x = 0;
	ifstream ifs("往届比赛.csv", ios::in);
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		this->FIE = true;
		ifs.close();
		return;
	}
	char n;
	ifs >> n;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		this->FIE = true;
		ifs.close();
		return;
	}
	ifs.putback(n);
	this->FIE = false;
	while (ifs >> data)
	{
		vector<string>ve;
		int pos = -1;
		int start = 0;
		while(1)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				break;
			}
			string temp = data.substr(start, pos-start);
			ve.push_back(temp);
			start = pos + 1;
		}
		Mrcord.insert(make_pair(x, ve));
		x++;
		data.clear();
	}
	ifs.close();
}
void SpechManager::showrecord()
{
	if (this->FIE == true)
	{
		cout << "文件不存在或为空" << endl;
	}
	for (int i = 0; i < this->Mrcord.size(); i++)
	{
		cout << "      第"<<i+1<<"届" << endl;
		cout << "冠军选手姓名：" << " " << Mrcord[i][0] << "冠军分数：" << Mrcord[i][1] << endl;
		cout << "亚军选手姓名：" << " " << Mrcord[i][2] << "亚军分数：" << Mrcord[i][3] << endl;
		cout << "季军选手姓名：" << " " << Mrcord[i][4] << "季军分数：" << Mrcord[i][5] << endl;
	}
	system("pause");
	system("cls");
}
void SpechManager::claearecord()
{
	cout << "是否清空？" << endl;
	cout << "1.是" << endl;
	cout << "2.否" << endl;
	int a = 0;
	cin >> a;
	if (a == 1)
	{
		ofstream ofs("往届比赛.csv", ios::trunc);
		ofs.close();
		initspeach();
		createspech();
		loadrecord();
		cout << "清空成功" << endl;
		system("pause");
	}
}