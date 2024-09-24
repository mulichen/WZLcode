#define  _CRT_SECURE_NO_WARNINGS
#include"manager.h"
Manager::Manager()
{

}
Manager::Manager(string name, string pwd)
{
	this->m_name = name;
	this->m_pwd = pwd;
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
	cout << "\t|          2.查看账号         \n";
	cout << "\t|                            |\n";
	cout << "\t|          3.查看预约         \n";
	cout << "\t|                            |\n";
	cout << "\t|          4.清空预约         \n";
	cout << "\t|                            |\n";
	cout << "\t|          5.注销登录         \n";
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
	cout << "  3.管理员" << endl;
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
	ofs << id << " " << name << " " << pwd << endl;
	ofs.close();
	cout << "添加成功" << endl;
	system("pause");
	system("cls");
}

//查看账号
void Manager::showPerson()
{

}
//查看机房信息
void Manager::showC()
{

}

//清空预约记录
void Manager::clearFile()
{

}