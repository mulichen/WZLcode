#define  _CRT_SECURE_NO_WARNINGS
#include"RSMR.h"
void menu()
{
	cout << "===========��ӭ���������ͻ���ԤԼϵͳ==========" << endl;
	cout << "�������������" << endl;
	cout << "\t\t---------------------\n";
	cout << "\t\t|    1.ѧ������     |\n";
	cout << "\t\t|                   |\n";
	cout << "\t\t|    2.��ʦ         |\n";
	cout << "\t\t|                   |\n";
	cout << "\t\t|    3.����Ա       |\n";
	cout << "\t\t|                   |\n";
	cout << "\t\t|    0.�˳�         |\n";
	cout << "\t\t|                   |\n";
	cout << "\t\t---------------------\n";
	cout << "��������ѡ��:" << endl;
}

//����Աģ��
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
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//ѧ��ģ��
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
			cout << "ע���ɹ�" << endl;
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
		cout << "�ļ���ʧ��" << endl;
		ifs.close();
		return;
	}
	int id=0;
	string name;
	string pwd;
	if (type == 1)
	{
		//ѧ����Ϣ
		cout << "������ѧ�����" << endl;
		cin >> id;
		cout << "����������" << endl;
		cin >> name;
		cout << "����������" << endl;
		cin >> pwd;
		int fid = 0;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "�����֤�ɹ�" << endl;
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
		//��ʦ��Ϣ
		cout << "��������ʦ���" << endl;
		cin >> id;
		cout << "����������" << endl;
		cin >> name;
		cout << "����������" << endl;
		cin >> pwd;
		int fid = 0;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "�����֤�ɹ�" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		person = new Teacher(id, name, pwd);
	}
	else if (type == 3)
	{
		//����Ա��Ϣ
		cout << "����������" << endl;
		cin >> name;
		cout << "����������" << endl;
		cin >> pwd;
		string fname;
		string fpwd;
		while (ifs >> fname && ifs >> fpwd)
		{
			if (fname == name && fpwd == pwd)
			{
				cout << "�����֤�ɹ�" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		person = new Manager(name, pwd);
		manager(person);
	}
	cout<<"�����֤ʧ��" << endl;
	ifs.close();
}

