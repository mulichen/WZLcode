#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<fstream>
class orderFile
{
public:
	//����
	orderFile();

	//����ԤԼ��Ϣ
	void updataorder();

	//��¼ԤԼ����
	int m_size;

	//��¼ԤԼ��Ϣ������
	vector<vector<string>>vo;
};