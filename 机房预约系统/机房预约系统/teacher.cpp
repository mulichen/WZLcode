#define  _CRT_SECURE_NO_WARNINGS
#include"teacher.h"
#include"orderfile.h"
Teacher::Teacher()
{
	this->m_Id = ""; // ��ʽ��ʼ��Ϊ0
	this->m_name = ""; // �����string���ͣ����Գ�ʼ��Ϊ���ַ���
	this->m_pwd = ""; // ͬ����ʼ������Ϊ���ַ���
}
Teacher::Teacher(string ID, string name, string pwd)
{
	this->m_Id = ID;
	this->m_name = name;
	this->m_pwd = pwd;
}
Teacher::~Teacher()
{

}

//�˵�
void Teacher::opermenu()
{
	cout << "��ӭ��ʦ: " << this->m_name << "��¼!" << endl;
	cout << "\t|------------------------------\n";
	cout << "\t|                             |\n";
	cout << "\t|          1.�鿴ԤԼ         |\n";
	cout << "\t|                             |\n";
	cout << "\t|          2.���ԤԼ         |\n";
	cout << "\t|                             |\n";
	cout << "\t|          5.ע����¼         |\n";
	cout << "\t|                             |\n";
	cout << "\t|------------------------------\n";
	cout << "��ѡ�����Ĳ���:" << endl;
}

//�鿴ȫ��ԤԼ
void Teacher::shoeAllOrder()
{
	orderFile of;
	if (of.m_size == 0)
	{
		cout<<"��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		for (vector<vector<string>>::iterator it = of.vo.begin(); it != of.vo.end(); it++)
		{
			vector <string>::iterator i = (*it).begin();
			cout << "ѧ�ţ�" << *i << " " << "������" << *(i + 1) << " " << "ԤԼ���ڣ���" << *(i + 2) << " " << "ʱ�Σ�" << (*(i + 3) == "1" ? "����" : "����") << " " << "������" << *(i + 4) << " ";
			string status = "״̬��";
			if (*(i + 5) == "1")
			{
				cout << status + "ԤԼ��" << endl;
			}
			else if (*(i + 5) == "2")
			{
				cout << status + "ԤԼ�ɹ�" << endl;
			}
			else if (*(i + 5) == "-1")
			{
				cout << status + "���δͨ����ԤԼʧ��" << endl;
			}
			else
			{
				cout << status + "ԤԼȡ��" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}

//���ԤԼ
void Teacher::validOrder()
{
	orderFile of;
	int num = 0;
	int b = 0;
	vector<int>v;
	for (vector<vector<string>>::iterator it = of.vo.begin(); it != of.vo.end(); it++)
	{
		vector <string>::iterator i = (*it).begin();
		if (*(i + 5) == "1")
		{
			cout << ++num << ",";
			cout << "ѧ�ţ�" << *i << " " << "������" << *(i + 1) << " " << "ԤԼ���ڣ���" << *(i + 2) << " " << "ʱ�Σ�" << (*(i + 3) == "1" ? "����" : "����") << " " << "������" << *(i + 4) << " ";
			string status = "״̬��";
			if (*(i + 5) == "1")
			{
				cout << status + "ԤԼ��" << endl;
			}
			v.push_back(b);
		}
		b++;
	}
	cout << "��������˵ļ�¼��0��ʾ����" << endl;
	int i;
	while (1)
	{
		cin >> i;
		if (i >= 0 && i <= v.size())
		{
			break;
		}
		else
			cout<<"�����������������" << endl;
	}
	if (i == 0)
	{
		return;
	}
	else
	{
		cout<<"��������˽��" << endl;
		cout << "1.ͨ��" << endl;
		cout << "2.��ͨ��" << endl;
		int p = 0;
		cin >> p;
		int x = v[i - 1];
		if (p == 1)
		{
			vector<vector<string>>::iterator it = of.vo.begin();
			(*(it + x)).pop_back();
			(*(it + x)).push_back("2");
			of.updataorder();
			cout << "���ͨ����" << endl;
			system("pause");
			system("cls");
		}
		else
		{
			vector<vector<string>>::iterator it = of.vo.begin();
			(*(it + x)).pop_back();
			(*(it + x)).push_back("-1");
			of.updataorder();
			cout << "��˲�ͨ����" << endl;
			system("pause");
			system("cls");
		}
	}
}