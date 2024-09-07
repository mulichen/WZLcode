#define  _CRT_SECURE_NO_WARNINGS
#include"workerM.h"
Work::Work()
{
	ifstream ifs;
		ifs.open("职工管理系统.txt", ios::in);
		if (!ifs.is_open())
		{
			cout << "文件打开失败" << endl;
			this->m_Empnum=0;
			this->m_workarray=nullptr;
			return;
		}
		char a;
		ifs >> a;
		if (ifs.eof())
		{
			cout << "文件为空" << endl;
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
	cout << "欢迎使用职工管理系统!" << endl;
	cout << "*********************************" << endl;
	cout << "1.增加职工信息" << endl;
	cout << "2.修改职工信息" << endl;
	cout << "3.查找职工信息" << endl;
	cout << "4.显示职工信息" << endl;
	cout << "5.按照编号排序" << endl;
	cout << "6.清空所有文档" << endl;
	cout << "7.删除离职职工" << endl;
	cout << "0.退出管理程序" << endl;
	cout << "*********************************" << endl;
}
void Work::addworker()
{
	int num = 0;
	cout << "请输入添加人数" << endl;
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
			cout << "请输入第" << j + 1 << "个的职工编号 " << endl;
			cin >> ID;
			cout << "请输入第" << j + 1 << "个的职工姓名 " << endl;
			cin >> name;
			cout << "请输入第" << j + 1 << "个的职工岗位 " << endl;
			cout << "1.员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.总裁" << endl;
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
		cout << "添加成功" << endl;
		delete this->m_workarray;
		m_workarray = newspace;
		this->m_Empnum = newsize;
	}
	else
	{
		cout << "输入错误" << endl;
	}
}
void Work::save(worker** m_workarray)
{
	ofstream ofs;
	ofs.open("职工管理系统.txt", ios::out);
	for (int i = 0; i < this->m_Empnum; i++)
	{
		ofs << m_workarray[i]->m_ID <<" " << m_workarray[i]->m_name<<" " << m_workarray[i]->m_DeptID << endl;
	}
	ofs.close();
	cout << "保存成功" << endl;
}
void Work::read()
{
	int a = 0;
	ifstream ifs;
	int ID;
	string name;
	int DID;
	ifs.open("职工管理系统.txt", ios::in);
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
	cout << "读取成功" << endl;
}
int Work::getnum()
{
	int num=0;
	ifstream ifs;
	ifs.open("职工管理系统.txt", ios::in);
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
		cout << "没有成员,无法显示" << endl;
}
void Work::Locate(worker** m_workarray)
{
	if (this->m_Empnum != 0)
	{
		int x = 0;
		int b = 0;
		//1.按姓名查找
		cout << "1.按姓名查找" << endl;
		//1.按
		cout << "2.按编号查找" << endl;
		cin >> b;
		if (b == 1)
		{
			string name;
			cout << "请输入查找人的姓名" << endl;
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
			cout << "请输入查找人的编号" << endl;
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
			cout << "查无此人" << endl;
			x--;
		}
	}
	cout << "没有成员，无法查找" << endl;
}
void Work::Modify(worker** m_workarray)
{
	if (this->m_Empnum != 0)
	{
		string name;
		cout << "请输要修改的人的姓名" << endl;
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
				cout << "请输入职工编号 " << endl;
				cin >> ID;
				cout << "请输入职工姓名 " << endl;
				cin >> name;
				cout << "请输入职工岗位 " << endl;
				cout << "1.员工" << endl;
				cout << "2.经理" << endl;
				cout << "3.总裁" << endl;
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
	cout << "没有成员，无法修改" << endl;

}
void Work::Sorting(worker** m_workarray)
{
	if (this->m_Empnum!=0)
	{
		int b = 0;
		//1.按姓名查找
		cout << "1.按姓名排序" << endl;
		//1.按
		cout << "2.按编号排序" << endl;
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
		cout << "没有成员，无法排序" << endl;
}
void Work::CTD(worker** m_workarray)
{
	int a = 0;
	cout << "请确认是否清空职工表" << endl;
	cout << "1. 是" << endl;
	cout << "2. 否" << endl;
	cin >> a;
	if (a == 1)
	{
		ofstream ofs("职工管理系统.txt", ios::trunc);
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
		cout << "清空成功" << endl;
		system("pause");
		system("cls");
	}
}
void Work::DWorker(worker** m_workarray)
{
	if (this->m_workarray != nullptr)
	{
		string name;
		cout << "请输入离职员工" << endl;
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
				cout << "删除完成" << endl;
			}
		}
	}
	cout << "没有成员，无需删除" << endl;
}