#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<fstream>
class orderFile
{
public:
	//构造
	orderFile();

	//更新预约信息
	void updataorder();

	//记录预约条数
	int m_size;

	//记录预约信息的容器
	vector<vector<string>>vo;
};