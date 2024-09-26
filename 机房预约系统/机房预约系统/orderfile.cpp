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
	while (ifs>>x)
	{
		v.push_back(x);
		i++;
		if (i % 6 == 0)
		{
			this->vo.push_back(v);
		}
	}
}

//更新预约信息
void orderFile::updataorder()
{

}