#define  _CRT_SECURE_NO_WARNINGS
#include"orderfile.h"
#include"globallfile.h"

//构造
orderFile::orderFile()
{
	ifstream ifs(ORDER_FILE,ios::in);
	string x;
	int i = 0;
	vector<string>v;
	this->m_size = 0;
	while (ifs>>x)
	{
		v.push_back(x);
		i++;
		if (i % 6 == 0)
		{
			this->vo.push_back(v);
			v.clear();
			this->m_size++;
		}
	}
}

//更新预约信息
void orderFile::updataorder()
{
	if (this->m_size == 0)
	{
		return;
	}
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (vector<vector<string>>::iterator it = vo.begin(); it != vo.end(); it++)
	{
		for (vector<string>::iterator i = (*it).begin(); i != (*it).end(); i++)
		{
			ofs << *i << " ";
		}
		ofs << endl;
	}
	ofs.close();
}