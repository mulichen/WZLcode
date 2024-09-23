#define  _CRT_SECURE_NO_WARNINGS
#include"SpechManager.h"
//cout << "************ 欢迎参加演讲比赛 ************" << endl;
//cout << "************  1.开始演讲比赛  ************" << endl;
//cout << "************  2.查看往届记录  ************" << endl;
//cout << "************  3.清空比赛记录  ************" << endl;
//cout << "************  0.退出比赛程序  ************" << endl;
int main()
{
	SpechManager sm;
	int S = 0;
	do
	{
		sm.shoe_menu();
		cout << "请选择：" << endl;
		cin >> S;
		switch (S)
		{
		case 1:
			sm.stackspech();
			break;
		case 2:
			sm.showrecord();
			break;
		case 3:
			sm.claearecord();
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			break;
		default:
			cout << "选择错误" << endl;
			system("pause");
			system("cls");
			break;
		}
	} while (S);
	system("pause");
	//system("cls");

	return 0;
}