#define  _CRT_SECURE_NO_WARNINGS
#include"student.h"
Student::Student()
{
	this->m_Id = ""; // ��ʽ��ʼ��Ϊ0
	this->m_name = ""; // �����string���ͣ����Գ�ʼ��Ϊ���ַ���
	this->m_pwd = ""; // ͬ����ʼ������Ϊ���ַ���
}
Student::Student(string ID, string name, string pwd)
{
	this->m_Id = ID;
	this->m_name = name;
	this->m_pwd = pwd;
	ifstream ifs(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		ifs.close();
	}
	int id = 0;
	int num = 0;
	Computer C;
	while (ifs >> C.m_id && ifs >> C.m_num)
	{
		vc.push_back(C);
	}
	ifs.close();
}
Student::~Student()
{

}
//�˵�
void Student::opermenu()
{

	cout << "��ӭѧ��: " << this->m_name << "��¼!" << endl;
	cout << "\t|------------------------------\n";
	cout << "\t|          1.����ԤԼ         |\n";
	cout << "\t|                             |\n";
	cout << "\t|          2.�鿴ԤԼ         |\n";
	cout << "\t|                             |\n";
	cout << "\t|          3.�鿴����ԤԼ     |\n";
	cout << "\t|                             |\n";
	cout << "\t|          4.ȡ��ԤԼ         |\n";
	cout << "\t|                             |\n";
	cout << "\t|          5.ע����¼         |\n";
	cout << "\t|                             |\n";
	cout << "\t|------------------------------\n";
	cout << "��ѡ�����Ĳ���:" << endl;
}

//����ԤԼ
void Student::applyOrder()
{
	cout<<"��ѡ��ԤԼ����" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;
	int i = 0;
	while (1)
	{
		cin >> i;
		if (i >= 1 && i <= 5)
		{
			break;
		}
		cout<<"ѡ���������������" << endl;
	}
	cout << "��ѡ��ʱ���" << endl;
	cout << "1.����" << endl;
	cout << "1.����" << endl;
	int j = 0;
	while (1)
	{
		cin >> j;
		if (j >= 1 && j <= 2)
		{
			break;
		}
		cout << "ѡ���������������" << endl;
	}
	cout << "��ѡ�񼸺Ż���" << endl;
	for (int i = 0; i < vc.size(); i++)
	{
		cout<<vc[i].m_id<<"�Ż���������" <<vc[i].m_num<<endl;
	}
	int k = 0;
	while (1)
	{
		cin >> k;
		if (k>= 1 && k <= 3)
		{
			break;
		}
		cout << "ѡ���������������" << endl;
	}
	cout<<"����ɹ��������" << endl;
	ofstream ofs(ORDER_FILE,ios::out|ios::app);
	ofs << this->m_Id << " " << this->m_name << " " << i << " " << j << " " << k << " " << 1 << endl;
	ofs.close();
	system("pause");
	system("cls");
}

//�鿴�ҵ�ԤԼ
void Student::showMyOrder()
{
	orderFile of;
	for (vector<vector<string>>::iterator it = of.vo.begin(); it != of.vo.end(); it++)
	{
		vector <string>::iterator i = (*it).begin();
		if (*i == this->m_Id)
		{
			cout << "ѧ�ţ�" << *i <<" "<< "������" << *(i + 1) << " " << "ԤԼ���ڣ���" << *(i + 2) << " " << "ʱ�Σ�" << (*(i + 3) == "1"?"����":"����")<< " " << "������"<<*(i+4)<<" "  ;
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

//�鿴ȫ��ԤԼ
void Student::shoeAllOrder()
{
	orderFile of;
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
	system("pause");
	system("cls");
}

//ȡ��ԤԼ
void Student::cancelOrder()
{
	cout << "�Ƿ�ȡ��ԤԼ" << endl;
	cout << "1�� ��" << endl;
	cout << "2�� ��" << endl;
	int i = 0;
	cin >> i;
	if (i == 1)
	{
		orderFile of;
		int num = 0;
		int b = 0;
		vector<int>v;
		for (vector<vector<string>>::iterator it = of.vo.begin(); it != of.vo.end(); it++)
		{
			vector <string>::iterator i = (*it).begin();
			if (*i == this->m_Id)
			{
				/*(*it).pop_back();
				(*it).push_back("3");*/
				if (*(i + 5) == "1" || *(i + 5) == "2")
				{
					cout << ++num << ",";
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
					v.push_back(b);
				}
			}
			b++;
		}
		cout << "������ȡ���ļ�¼��0��ʾ����" << endl;
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
			int x = 0;
			x = v[i - 1];
			vector<vector<string>>::iterator it = of.vo.begin();
			(*(it + x)).pop_back();
			(*(it + x)).push_back("3");
			of.updataorder();
			cout << "ȡ���ɹ���" << endl;
			system("pause");
			system("cls");
		}
	}
}
