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

//�˵�
void Manager::opermenu()
{
		cout << "��ӭ����Ա: " << this->m_name << "��¼!" << endl;
	cout << "\t|-----------------------------\n";
	cout << "\t|          1.����˺�        |\n";
	cout << "\t|                            |\n";
	cout << "\t|          2.�鿴�˺�         \n";
	cout << "\t|                            |\n";
	cout << "\t|          3.�鿴ԤԼ         \n";
	cout << "\t|                            |\n";
	cout << "\t|          4.���ԤԼ         \n";
	cout << "\t|                            |\n";
	cout << "\t|          5.ע����¼         \n";
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
	cout << "  3.����Ա" << endl;
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
	ofs << id << " " << name << " " << pwd << endl;
	ofs.close();
	cout << "��ӳɹ�" << endl;
	system("pause");
	system("cls");
}

//�鿴�˺�
void Manager::showPerson()
{

}
//�鿴������Ϣ
void Manager::showC()
{

}

//���ԤԼ��¼
void Manager::clearFile()
{

}