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
	cout << "************ ��ӭ�μ��ݽ����� ************" << endl;
	cout << "************  1.��ʼ�ݽ�����  ************" << endl;
	cout << "************  2.�鿴�����¼  ************" << endl;
	cout << "************  3.��ձ�����¼  ************" << endl;
	cout << "************  0.�˳���������  ************" << endl;
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
		string name = "����";
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
	cout << "      ��<<" << this->m_Index << ">>�ֱ�����ǩ�����" << endl;
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
	cout << "      ��<<" << this->m_Index << ">>�ֱ�����ʼ��" << endl;
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
			cout << "      ��<<" <<num/6<< ">>С����������" << endl;
			for (multimap<double, int, greater<double>>::iterator it1 = groupscore.begin(); it1 != groupscore.end(); it1++)
			{
				cout << "��ţ�" << it1->second << "������" << this->M[it1->second].m_name << "������" << this->M[it1->second].m_score[this->m_Index - 1] << endl;
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
	cout << "      ��<<" << this->m_Index << ">>�ֱ�������" << endl;
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
	cout << "      ��<<" << this->m_Index << ">>�ֽ���������" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "��ţ�" << *it<< "������" << this->M[*it].m_name << "������" << this->M[*it].m_score[this->m_Index - 1] << endl;
	}
	system("pause");
}
void SpechManager::savescore()
{
	ofstream ofs;
	ofs.open("�������.csv", ios::out | ios::app);
	for (vector<int>::iterator it = V.begin(); it != V.end(); it++)
	{
		ofs<<*it<<","<< this->M[*it].m_score[1]<<",";
	}
	ofs << endl;
	ofs.close();
	cout << "�������" << endl;
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
	ifstream ifs("�������.csv", ios::in);
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		this->FIE = true;
		ifs.close();
		return;
	}
	char n;
	ifs >> n;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
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
		cout << "�ļ������ڻ�Ϊ��" << endl;
	}
	for (int i = 0; i < this->Mrcord.size(); i++)
	{
		cout << "      ��"<<i+1<<"��" << endl;
		cout << "�ھ�ѡ��������" << " " << Mrcord[i][0] << "�ھ�������" << Mrcord[i][1] << endl;
		cout << "�Ǿ�ѡ��������" << " " << Mrcord[i][2] << "�Ǿ�������" << Mrcord[i][3] << endl;
		cout << "����ѡ��������" << " " << Mrcord[i][4] << "����������" << Mrcord[i][5] << endl;
	}
	system("pause");
	system("cls");
}
void SpechManager::claearecord()
{
	cout << "�Ƿ���գ�" << endl;
	cout << "1.��" << endl;
	cout << "2.��" << endl;
	int a = 0;
	cin >> a;
	if (a == 1)
	{
		ofstream ofs("�������.csv", ios::trunc);
		ofs.close();
		initspeach();
		createspech();
		loadrecord();
		cout << "��ճɹ�" << endl;
		system("pause");
	}
}