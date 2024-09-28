#define  _CRT_SECURE_NO_WARNINGS
#include"teacher.h"
#include"orderfile.h"
Teacher::Teacher()
{
	this->m_Id = ""; // 显式初始化为0
	this->m_name = ""; // 如果是string类型，可以初始化为空字符串
	this->m_pwd = ""; // 同样初始化密码为空字符串
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

//菜单
void Teacher::opermenu()
{
	cout << "欢迎老师: " << this->m_name << "登录!" << endl;
	cout << "\t|------------------------------\n";
	cout << "\t|                             |\n";
	cout << "\t|          1.查看预约         |\n";
	cout << "\t|                             |\n";
	cout << "\t|          2.审核预约         |\n";
	cout << "\t|                             |\n";
	cout << "\t|          5.注销登录         |\n";
	cout << "\t|                             |\n";
	cout << "\t|------------------------------\n";
	cout << "请选择您的操作:" << endl;
}

//查看全部预约
void Teacher::shoeAllOrder()
{
	orderFile of;
	if (of.m_size == 0)
	{
		cout<<"无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		for (vector<vector<string>>::iterator it = of.vo.begin(); it != of.vo.end(); it++)
		{
			vector <string>::iterator i = (*it).begin();
			cout << "学号：" << *i << " " << "姓名：" << *(i + 1) << " " << "预约日期，周" << *(i + 2) << " " << "时段：" << (*(i + 3) == "1" ? "上午" : "下午") << " " << "机房：" << *(i + 4) << " ";
			string status = "状态：";
			if (*(i + 5) == "1")
			{
				cout << status + "预约中" << endl;
			}
			else if (*(i + 5) == "2")
			{
				cout << status + "预约成功" << endl;
			}
			else if (*(i + 5) == "-1")
			{
				cout << status + "审核未通过！预约失败" << endl;
			}
			else
			{
				cout << status + "预约取消" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}

//审核预约
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
			cout << "学号：" << *i << " " << "姓名：" << *(i + 1) << " " << "预约日期，周" << *(i + 2) << " " << "时段：" << (*(i + 3) == "1" ? "上午" : "下午") << " " << "机房：" << *(i + 4) << " ";
			string status = "状态：";
			if (*(i + 5) == "1")
			{
				cout << status + "预约中" << endl;
			}
			v.push_back(b);
		}
		b++;
	}
	cout << "请输入审核的记录，0表示返回" << endl;
	int i;
	while (1)
	{
		cin >> i;
		if (i >= 0 && i <= v.size())
		{
			break;
		}
		else
			cout<<"输入错误！请重新输入" << endl;
	}
	if (i == 0)
	{
		return;
	}
	else
	{
		cout<<"请输入审核结果" << endl;
		cout << "1.通过" << endl;
		cout << "2.不通过" << endl;
		int p = 0;
		cin >> p;
		int x = v[i - 1];
		if (p == 1)
		{
			vector<vector<string>>::iterator it = of.vo.begin();
			(*(it + x)).pop_back();
			(*(it + x)).push_back("2");
			of.updataorder();
			cout << "审核通过！" << endl;
			system("pause");
			system("cls");
		}
		else
		{
			vector<vector<string>>::iterator it = of.vo.begin();
			(*(it + x)).pop_back();
			(*(it + x)).push_back("-1");
			of.updataorder();
			cout << "审核不通过！" << endl;
			system("pause");
			system("cls");
		}
	}
}