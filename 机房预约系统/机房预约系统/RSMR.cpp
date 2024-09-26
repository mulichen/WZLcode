#define  _CRT_SECURE_NO_WARNINGS
#include"RSMR.h"
void menu()
{
	cout << "===========欢迎来到传播客机房预约系统==========" << endl;
	cout << "请输入您的身份" << endl;
	cout << "\t\t---------------------\n";
	cout << "\t\t|    1.学生代表     |\n";
	cout << "\t\t|                   |\n";
	cout << "\t\t|    2.老师         |\n";
	cout << "\t\t|                   |\n";
	cout << "\t\t|    3.管理员       |\n";
	cout << "\t\t|                   |\n";
	cout << "\t\t|    0.退出         |\n";
	cout << "\t\t|                   |\n";
	cout << "\t\t---------------------\n";
	cout << "输入您的选择:" << endl;
}

//管理员模块
void  manager(Identity* &manager)
{
	while (1)
	{
		manager->opermenu();
		Manager* man = (Manager*)manager;
		int i = 0;
		cin >> i;
		switch (i)
		{
		case 1:
			man->AddPerson();
			break;
		case 2:
			man->showPerson();
			break;
		case 3:
			man->showC();
			break;
		case 4:
			man->clearFile();
			break;
		default:
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//学生模块
void student(Identity* &student)
{
	while (1)
	{
		student->opermenu();
		Student* stu = (Student*)student;
		int i = 0;
		cin >> i;
		switch (i)
		{
		case 1:
			stu->applyOrder();
			break;
		case 2:
			stu->showMyOrder();
			break;
		case 3:
			stu->shoeAllOrder();
			break;
		case 4:
			stu->cancelOrder();
			break;
		default:
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


void loginIn(string filename, int type)
{
	Identity* person = nullptr;
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		ifs.close();
		return;
	}
	int id=0;
	string name;
	string pwd;
	if (type == 1)
	{
		//学生信息
		cout << "请输入学生编号" << endl;
		cin >> id;
		cout << "请输入姓名" << endl;
		cin >> name;
		cout << "请输入密码" << endl;
		cin >> pwd;
		int fid = 0;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "身份验证成功" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		person = new Student(id, name, pwd);
		student(person);
	}
	else if (type == 2)
	{
		//老师信息
		cout << "请输入老师编号" << endl;
		cin >> id;
		cout << "请输入姓名" << endl;
		cin >> name;
		cout << "请输入密码" << endl;
		cin >> pwd;
		int fid = 0;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "身份验证成功" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		person = new Teacher(id, name, pwd);
	}
	else if (type == 3)
	{
		//管理员信息
		cout << "请输入姓名" << endl;
		cin >> name;
		cout << "请输入密码" << endl;
		cin >> pwd;
		string fname;
		string fpwd;
		while (ifs >> fname && ifs >> fpwd)
		{
			if (fname == name && fpwd == pwd)
			{
				cout << "身份验证成功" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		person = new Manager(name, pwd);
		manager(person);
	}
	cout<<"身份验证失败" << endl;
	ifs.close();
}

