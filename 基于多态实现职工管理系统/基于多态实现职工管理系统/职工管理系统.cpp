#define  _CRT_SECURE_NO_WARNINGS
#include"workerM.h"
//cout << "欢迎使用职工管理系统!" << endl;
//cout << "*********************************" << endl;
//cout << "1.增加职工信息" << endl;
//cout << "2.修改职工信息" << endl;
//cout << "3.查找职工信息" << endl;
//cout << "4.显示职工信息" << endl;
//cout << "5.按照编号排序" << endl;
//cout << "6.清空所有文档" << endl;
//cout << "7.删除离职职工" << endl;
//cout << "0.退出管理程序" << endl;
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
			cout << "欢迎下次使用" << endl;
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