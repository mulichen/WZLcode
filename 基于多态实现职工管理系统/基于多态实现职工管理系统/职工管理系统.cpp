#define  _CRT_SECURE_NO_WARNINGS
#include"workerM.h"
//cout << "��ӭʹ��ְ������ϵͳ!" << endl;
//cout << "*********************************" << endl;
//cout << "1.����ְ����Ϣ" << endl;
//cout << "2.�޸�ְ����Ϣ" << endl;
//cout << "3.����ְ����Ϣ" << endl;
//cout << "4.��ʾְ����Ϣ" << endl;
//cout << "5.���ձ������" << endl;
//cout << "6.��������ĵ�" << endl;
//cout << "7.ɾ����ְְ��" << endl;
//cout << "0.�˳��������" << endl;
//cout << "*********************************" << endl;
int main()
{
	Work W;
	int num=0;
	do
	{
		W.show_num();
		cin >> num;
		switch (num)
		{
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			break;
		case 1:
            W.addworker();
			break;
		case 2:
			W.Modify(W.m_workarray);
			break;
		case 3:
			W.Locate(W.m_workarray);
			break;
		case 4:
			W.showworker(W.m_workarray);
			break;
		case 5:
			W.Sorting(W.m_workarray);
			break;
		case 6:
			W.CTD(W.m_workarray);
			break;
		case 7:
			W.DWorker(W.m_workarray);
			break;
		default:
			break;
		}
		W.save(W.m_workarray);
	} while (num);
	return 0;
}