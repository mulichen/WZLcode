#define  _CRT_SECURE_NO_WARNINGS
#include"SpechManager.h"
//cout << "************ ��ӭ�μ��ݽ����� ************" << endl;
//cout << "************  1.��ʼ�ݽ�����  ************" << endl;
//cout << "************  2.�鿴�����¼  ************" << endl;
//cout << "************  3.��ձ�����¼  ************" << endl;
//cout << "************  0.�˳���������  ************" << endl;
int main()
{
	SpechManager sm;
	int S = 0;
	do
	{
		sm.shoe_menu();
		cout << "��ѡ��" << endl;
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
			cout << "��ӭ�´�ʹ��" << endl;
			break;
		default:
			cout << "ѡ�����" << endl;
			system("pause");
			system("cls");
			break;
		}
	} while (S);
	system("pause");
	//system("cls");

	return 0;
}