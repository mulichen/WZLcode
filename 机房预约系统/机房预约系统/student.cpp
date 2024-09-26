#define  _CRT_SECURE_NO_WARNINGS
#include"student.h"
Student::Student()
{
	this->m_Id = 0; // 显式初始化为0
	this->m_name = ""; // 如果是string类型，可以初始化为空字符串
	this->m_pwd = ""; // 同样初始化密码为空字符串
}
Student::Student(int ID, string name, string pwd)
{
	this->m_Id = ID;
	this->m_name = name;
	this->m_pwd = pwd;
	ifstream ifs(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
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
//菜单
void Student::opermenu()
{

	cout << "欢迎学生: " << this->m_name << "登录!" << endl;
	cout << "\t|------------------------------\n";
	cout << "\t|          1.申请预约         |\n";
	cout << "\t|                             |\n";
	cout << "\t|          2.查看预约         |\n";
	cout << "\t|                             |\n";
	cout << "\t|          3.查看所有预约     |\n";
	cout << "\t|                             |\n";
	cout << "\t|          4.取消预约         |\n";
	cout << "\t|                             |\n";
	cout << "\t|          5.注销登录         |\n";
	cout << "\t|                             |\n";
	cout << "\t|------------------------------\n";
	cout << "请选择您的操作:" << endl;
}

//申请预约
void Student::applyOrder()
{
	cout<<"请选择预约日期" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;
	int i = 0;
	while (1)
	{
		cin >> i;
		if (i >= 1 && i <= 5)
		{
			break;
		}
		cout<<"选择错误！请重新输入" << endl;
	}
	cout << "请选择时间段" << endl;
	cout << "1.上午" << endl;
	cout << "1.下午" << endl;
	int j = 0;
	while (1)
	{
		cin >> j;
		if (j >= 1 && j <= 2)
		{
			break;
		}
		cout << "选择错误！请重新输入" << endl;
	}
	cout << "请选择几号机房" << endl;
	for (int i = 0; i < vc.size(); i++)
	{
		cout<<vc[i].m_id<<"号机房容量：" <<vc[i].m_num<<endl;
	}
	int k = 0;
	while (1)
	{
		cin >> k;
		if (k>= 1 && k <= 3)
		{
			break;
		}
		cout << "选择错误！请重新输入" << endl;
	}
	cout<<"申请成功！审核中" << endl;
	ofstream ofs(ORDER_FILE,ios::out|ios::app);
	ofs << this->m_Id << " " << this->m_name << " " << i << " " << j << " " << k << " " << 1 << endl;
	ofs.close();
	system("pause");
	system("cls");
}

//查看我的预约
void Student::showMyOrder()
{

}

//查看全部预约
void Student::shoeAllOrder()
{

}

//取消预约
void Student::cancelOrder()
{

}
