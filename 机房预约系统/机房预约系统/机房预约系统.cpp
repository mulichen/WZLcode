#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"RSMR.h"
using namespace std;
int main()
{
	while (1)
	{
		menu();
		int i = 0;
		cin >> i;
		switch (i)
		{
		case 1:
			loginIn(STUDENT_FILE, 1);
			break;
		case 2:
			loginIn(TEACHER_FILE, 2);
			break;
		case 3:
			loginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}