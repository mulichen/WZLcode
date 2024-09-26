#define  _CRT_SECURE_NO_WARNINGS
#include"manager.h"
Manager::Manager()
{

}
Manager::Manager(string name, string pwd)
{
	this->m_name = name;
	this->m_pwd = pwd;
	intvector();
	ifstream ifs(COMPUTER_FILE,ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		ifs.close();
	}
	int id = 0;
	int num = 0;
	Computer C;
	while (ifs >>C.m_id && ifs >>C.m_num)
	{
		vc.push_back(C);
	}
	ifs.close();
}
Manager::~Manager()
{

}

//�˵�
void Manager::opermenu()
{
		cout << "��ӭ����Ա: " << this->m_name << "��¼!" << endl;
	cout << "\t|-----------------------------\n";
	cout << "\t|          1.����˺�        |\n";
	cout << "\t|                            |\n";
	cout << "\t|          2.�鿴�˺�        |\n";
	cout << "\t|                            |\n";
	cout << "\t|          3.�鿴ԤԼ        |\n";
	cout << "\t|                            |\n";
	cout << "\t|          4.���ԤԼ        |\n";
	cout << "\t|                            |\n";
	cout << "\t|          5.ע����¼        |\n";
	cout << "\t|                            |\n";
	cout << "\t|-----------------------------\n";
	cout << "��ѡ�����Ĳ���:" << endl;
}

//����˺�
void Manager::AddPerson()
{
	cout << "��������������" << endl;
	cout << "  1.ѧ��" << endl;
	cout << "  2.��ʦ" << endl;
	int i = 0;
	cin >> i;
	string filename;
	string p;
	if (i == 1)
	{
		filename = STUDENT_FILE;
		p = "����ѧ�����";
	}
	else if (i == 2)
	{
		filename = TEACHER_FILE;
		p = "������ʦ���";
	}
	ofstream ofs;
	ofs.open(filename, ios::out | ios::app);
	cout << p << endl;
	int id = 0;
	cin >> id;
	string name;
	cout << "����������" << endl;
	cin >> name;
	string pwd;
	cout << "����������" << endl;
	cin >> pwd;
	bool x = checkrepeat(id, i);
	if (!x)
	{
		ofs << id << " " << name << " " << pwd << endl;
		ofs.close();
		if (i == 1)
		{
			Student s(id,name,pwd);
			vs.push_back(s);
		}
		else if (i == 2)
		{
			Teacher s(id, name, pwd);
			vt.push_back(s);
		}
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout<<"��ų����ظ��������²���" << endl;
		system("pause");
		system("cls");
	}
}

//�鿴�˺�
void ps(Student S)
{
	cout << "ѧ�����" << S.m_Id<<"����"<<S.m_name<<"����" <<S.m_pwd<< endl;
}
void pt(Teacher T)
{
	cout << "��ʦ���" << T.m_Id << "����" << T.m_name << "����" << T.m_pwd << endl;
}
void Manager::showPerson()
{
	cout << "������鿴�����" << endl;
	cout << "1.����ѧ��" << endl;
	cout << "2.������ʦ" << endl;
	int i = 0;
	cin >> i;
	if (i == 1)
	{
		cout << "1.����ѧ����Ϣ����" << endl;
		for_each(vs.begin(), vs.end(), ps);
	}
	else if (i == 2)
	{
		cout << "1.������ʦ��Ϣ����" << endl;
		for_each(vt.begin(), vt.end(), pt);
	}

}
//�鿴������Ϣ
void Manager::showC()
{
	cout <<"������Ϣ���£�" << endl;
	for (vector<Computer>::iterator it = vc.begin(); it != vc.end(); it++)
	{
		cout<<"������ţ�"<<it->m_id <<"����������"<<it->m_num<<endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::clearFile()
{
	ifstream ifs(ORDER_FILE, ios::trunc);
	ifs.close();
	cout<<"��ճɹ���" << endl;
	system("pause");
	system("cls");
}

//��ʼ������
void Manager::intvector()
{
	//ѧ������
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout<<"�ļ���ȡʧ��" << endl;
		ifs.close();
		return;
	}
	vs.clear();
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_name && ifs >> s.m_pwd)
	{
		vs.push_back(s);
	}
	ifs.close();

	//��ʦ����
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		ifs.close();
		return;
	}
	vt.clear();
	Teacher t;
	while (ifs >> t.m_Id && ifs >> t.m_name && ifs >> t.m_pwd)
	{
		vt.push_back(t);
	}
	ifs.close();
}

//����ظ�
bool Manager::checkrepeat(int id, int pty)
{
	if (pty == 1)
	{
		//���ѧ��
		for (vector<Student>::iterator it = vs.begin(); it != vs.end(); it++)
		{
			if (it->m_Id == id)
			{
				return true;
			}
		}
	}
	else
	{
		//�����ʦ
		for (vector<Teacher>::iterator it = vt.begin(); it != vt.end(); it++)
		{
			if (it->m_Id == id)
			{
				return true;
			}
		}
	}
	return false;
}

