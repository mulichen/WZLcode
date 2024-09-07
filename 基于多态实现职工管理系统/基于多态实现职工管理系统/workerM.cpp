#define  _CRT_SECURE_NO_WARNINGS
#include"workerM.h"
Work::Work()
{
	ifstream ifs;
		ifs.open("ְ������ϵͳ.txt", ios::in);
		if (!ifs.is_open())
		{
			cout << "�ļ���ʧ��" << endl;
			this->m_Empnum=0;
			this->m_workarray=nullptr;
			return;
		}
		char a;
		ifs >> a;
		if (ifs.eof())
		{
			cout << "�ļ�Ϊ��" << endl;
			this->m_Empnum = 0;
			this->m_workarray = nullptr;
			return;
		}
		int Num = this->getnum();
		this->m_workarray= new worker * [Num];
		this->m_Empnum = Num;
		this->read();
}
Work::~Work()
{
	if (this->m_workarray != nullptr)
	{

		for (int a = 0; a < this->m_Empnum; a++)
		{
			if (m_workarray[a] != nullptr)
			{
				delete m_workarray[a];
				m_workarray[a] = nullptr;
			}
		}
		delete this->m_workarray;
		this->m_workarray = nullptr;
	}
}
void Work::show_num()
{
	cout << "��ӭʹ��ְ������ϵͳ!" << endl;
	cout << "*********************************" << endl;
	cout << "1.����ְ����Ϣ" << endl;
	cout << "2.�޸�ְ����Ϣ" << endl;
	cout << "3.����ְ����Ϣ" << endl;
	cout << "4.��ʾְ����Ϣ" << endl;
	cout << "5.���ձ������" << endl;
	cout << "6.��������ĵ�" << endl;
	cout << "7.ɾ����ְְ��" << endl;
	cout << "0.�˳��������" << endl;
	cout << "*********************************" << endl;
}
void Work::addworker()
{
	int num = 0;
	cout << "�������������" << endl;
	cin >> num;
	if (num > 0)
	{
		int newsize = this->m_Empnum + num;
		worker **newspace = new worker * [newsize+4];
		if(this->m_workarray!=nullptr)
		{
			for (int i = 0; i < this->m_Empnum; i++)
			{
				newspace[i] = this->m_workarray[i];
			}
		}
		for (int j = 0; j < num; j++)
		{
			int ID;
			string name;
			int D_ID;
			cout << "�������" << j + 1 << "����ְ����� " << endl;
			cin >> ID;
			cout << "�������" << j + 1 << "����ְ������ " << endl;
			cin >> name;
			cout << "�������" << j + 1 << "����ְ����λ " << endl;
			cout << "1.Ա��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ܲ�" << endl;
			cin >> D_ID;
			worker* employee = nullptr;
			switch (D_ID)
			{
			case 1:
				employee = new Employee(ID, name, D_ID);
				break;
			case 2:
				employee = new Manager(ID, name, D_ID);
				break;
			case 3:
				employee = new Boss(ID, name, D_ID);
				break;
			default:
				break;
			}
			newspace[this->m_Empnum + j] = employee;
		}
		cout << "��ӳɹ�" << endl;
		delete this->m_workarray;
		m_workarray = newspace;
		this->m_Empnum = newsize;
	}
	else
	{
		cout << "�������" << endl;
	}
}
void Work::save(worker** m_workarray)
{
	ofstream ofs;
	ofs.open("ְ������ϵͳ.txt", ios::out);
	for (int i = 0; i < this->m_Empnum; i++)
	{
		ofs << m_workarray[i]->m_ID <<" " << m_workarray[i]->m_name<<" " << m_workarray[i]->m_DeptID << endl;
	}
	ofs.close();
	cout << "����ɹ�" << endl;
}
void Work::read()
{
	int a = 0;
	ifstream ifs;
	int ID;
	string name;
	int DID;
	ifs.open("ְ������ϵͳ.txt", ios::in);
	while (ifs >> ID && ifs >> name && ifs >> DID)
	{
		worker* employee = nullptr;
		if (DID==1)
		{
			employee = new Employee(ID, name, DID);
		}
		if (DID == 2)
		{
			employee = new Manager(ID, name, DID);
		}
		if (DID == 3)
		{
			employee = new Boss(ID, name, DID);
		}
		this->m_workarray[a] = employee;
		a++;
	}
	ifs.close();
	cout << "��ȡ�ɹ�" << endl;
}
int Work::getnum()
{
	int num=0;
	ifstream ifs;
	ifs.open("ְ������ϵͳ.txt", ios::in);
	int ID;
	string name;
	int DID;
	while (ifs >> ID && ifs >> name && ifs >> DID)
	{
		num++;
	}
	ifs.close();
	return num;
}

void Work::showworker(worker** m_workarray)
{
	if (this->m_Empnum != 0)
	{
		for (int i = 0; i < this->m_Empnum; i++)
		{
			m_workarray[i]->showInfo();
		}
	}
	else
		cout << "û�г�Ա,�޷���ʾ" << endl;
}
void Work::Locate(worker** m_workarray)
{
	if (this->m_Empnum != 0)
	{
		int x = 0;
		int b = 0;
		//1.����������
		cout << "1.����������" << endl;
		//1.��
		cout << "2.����Ų���" << endl;
		cin >> b;
		if (b == 1)
		{
			string name;
			cout << "����������˵�����" << endl;
			cin >> name;
			for (int a = 0; a < this->m_Empnum; a++)
			{
				if (m_workarray[a]->m_name == name)
				{
					m_workarray[a]->showInfo();
					x++;
					break;
				}
			}
		}
		if (b == 2)
		{
			int c;
			cout << "����������˵ı��" << endl;
			cin >> c;
			for (int a = 0; a < this->m_Empnum; a++)
			{
				if (m_workarray[a]->m_ID == c)
				{
					m_workarray[a]->showInfo();
					x++;
					break;
				}
			}
		}
		if (x == 0)
		{
			cout << "���޴���" << endl;
			x--;
		}
	}
	cout << "û�г�Ա���޷�����" << endl;
}
void Work::Modify(worker** m_workarray)
{
	if (this->m_Empnum != 0)
	{
		string name;
		cout << "����Ҫ�޸ĵ��˵�����" << endl;
		cin >> name;
		for (int a = 0; a < this->m_Empnum; a++)
		{
			if (m_workarray[a]->m_name == name)
			{

				m_workarray[a]->showInfo();
				int ID;
				string name;
				int DID;
				cout << "------------------------" << endl;
				cout << "������ְ����� " << endl;
				cin >> ID;
				cout << "������ְ������ " << endl;
				cin >> name;
				cout << "������ְ����λ " << endl;
				cout << "1.Ա��" << endl;
				cout << "2.����" << endl;
				cout << "3.�ܲ�" << endl;
				cin >> DID;
				worker* employee = nullptr;
				if (DID == 1)
				{
					employee = new Employee(ID, name, DID);
				}
				if (DID == 2)
				{
					employee = new Manager(ID, name, DID);
				}
				if (DID == 3)
				{
					employee = new Boss(ID, name, DID);
				}
				this->m_workarray[a] = employee;
				break;
			}
		}
	}
	cout << "û�г�Ա���޷��޸�" << endl;

}
void Work::Sorting(worker** m_workarray)
{
	if (this->m_Empnum!=0)
	{
		int b = 0;
		//1.����������
		cout << "1.����������" << endl;
		//1.��
		cout << "2.���������" << endl;
		cin >> b;
		worker* employee = nullptr;
		if (b == 1)
		{
			bool swap;
			for (int j = 0; j < this->m_Empnum - 1; j++)
			{
				swap = false;
				for (int a = 0; a < this->m_Empnum - j - 1; a++)
				{
					if (m_workarray[a]->m_name > m_workarray[a + 1]->m_name)
					{
						employee = m_workarray[a];
						m_workarray[a] = m_workarray[a + 1];
						m_workarray[a + 1] = employee;
						swap = true;
					}
				}
				if (!swap)
				{
					break;
				}
			}

		}
		if (b == 2)
		{
			bool swap;
			for (int j = 0; j < this->m_Empnum - 1; j++)
			{
				swap = false;
				for (int a = 0; a < this->m_Empnum - j - 1; a++)
				{
					if (m_workarray[a]->m_ID > m_workarray[a + 1]->m_ID)
					{
						employee = m_workarray[a];
						m_workarray[a] = m_workarray[a + 1];
						m_workarray[a + 1] = employee;
						swap = true;
					}
				}
				if (!swap)
				{
					break;
				}
			}
		}
	}
	else
		cout << "û�г�Ա���޷�����" << endl;
}
void Work::CTD(worker** m_workarray)
{
	int a = 0;
	cout << "��ȷ���Ƿ����ְ����" << endl;
	cout << "1. ��" << endl;
	cout << "2. ��" << endl;
	cin >> a;
	if (a == 1)
	{
		ofstream ofs("ְ������ϵͳ.txt", ios::trunc);
		ofs.close();
		if (this->m_workarray != nullptr)
		{
			for (int a = 0; a < this->m_Empnum; a++)
			{
				if (m_workarray[a] != nullptr)
				{
					delete m_workarray[a];
					m_workarray[a] = nullptr;
				}
			}
			delete[] this->m_workarray;
			this->m_workarray = nullptr;
			this->m_Empnum = 0;
		}
		cout << "��ճɹ�" << endl;
		system("pause");
		system("cls");
	}
}
void Work::DWorker(worker** m_workarray)
{
	if (this->m_workarray != nullptr)
	{
		string name;
		cout << "��������ְԱ��" << endl;
		cin >> name;
		for (int a = 0; a < this->m_Empnum; a++)
		{
			if (m_workarray[a]->m_name == name)
			{
				delete  m_workarray[a];
				for (int j = a; a < this->m_Empnum; a++)
				{
					m_workarray[a] = m_workarray[a + 1];
				}
				this->m_Empnum--;
				break;
				cout << "ɾ�����" << endl;
			}
		}
	}
	cout << "û�г�Ա������ɾ��" << endl;
}