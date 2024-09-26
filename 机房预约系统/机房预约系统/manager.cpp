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
		cout << "文件打开失败" << endl;
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

//菜单
void Manager::opermenu()
{
		cout << "欢迎管理员: " << this->m_name << "登录!" << endl;
	cout << "\t|-----------------------------\n";
	cout << "\t|          1.添加账号        |\n";
	cout << "\t|                            |\n";
	cout << "\t|          2.查看账号        |\n";
	cout << "\t|                            |\n";
	cout << "\t|          3.查看预约        |\n";
	cout << "\t|                            |\n";
	cout << "\t|          4.清空预约        |\n";
	cout << "\t|                            |\n";
	cout << "\t|          5.注销登录        |\n";
	cout << "\t|                            |\n";
	cout << "\t|-----------------------------\n";
	cout << "请选择您的操作:" << endl;
}

//添加账号
void Manager::AddPerson()
{
	cout << "请输入添加人身份" << endl;
	cout << "  1.学生" << endl;
	cout << "  2.老师" << endl;
	int i = 0;
	cin >> i;
	string filename;
	string p;
	if (i == 1)
	{
		filename = STUDENT_FILE;
		p = "输入学生编号";
	}
	else if (i == 2)
	{
		filename = TEACHER_FILE;
		p = "输入老师编号";
	}
	ofstream ofs;
	ofs.open(filename, ios::out | ios::app);
	cout << p << endl;
	int id = 0;
	cin >> id;
	string name;
	cout << "请输入姓名" << endl;
	cin >> name;
	string pwd;
	cout << "请输入密码" << endl;
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
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout<<"编号出现重复，请重新操作" << endl;
		system("pause");
		system("cls");
	}
}

//查看账号
void ps(Student S)
{
	cout << "学生编号" << S.m_Id<<"姓名"<<S.m_name<<"密码" <<S.m_pwd<< endl;
}
void pt(Teacher T)
{
	cout << "老师编号" << T.m_Id << "姓名" << T.m_name << "密码" << T.m_pwd << endl;
}
void Manager::showPerson()
{
	cout << "请输入查看的身份" << endl;
	cout << "1.所有学生" << endl;
	cout << "2.所有老师" << endl;
	int i = 0;
	cin >> i;
	if (i == 1)
	{
		cout << "1.所有学生信息如下" << endl;
		for_each(vs.begin(), vs.end(), ps);
	}
	else if (i == 2)
	{
		cout << "1.所有老师信息如下" << endl;
		for_each(vt.begin(), vt.end(), pt);
	}

}
//查看机房信息
void Manager::showC()
{
	cout <<"机房信息如下：" << endl;
	for (vector<Computer>::iterator it = vc.begin(); it != vc.end(); it++)
	{
		cout<<"机房编号："<<it->m_id <<"机房容量："<<it->m_num<<endl;
	}
	system("pause");
	system("cls");
}

//清空预约记录
void Manager::clearFile()
{
	ifstream ifs(ORDER_FILE, ios::trunc);
	ifs.close();
	cout<<"清空成功！" << endl;
	system("pause");
	system("cls");
}

//初始化容器
void Manager::intvector()
{
	//学生容器
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout<<"文件读取失败" << endl;
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

	//老师容器
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
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

//检测重复
bool Manager::checkrepeat(int id, int pty)
{
	if (pty == 1)
	{
		//检测学生
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
		//检测老师
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

