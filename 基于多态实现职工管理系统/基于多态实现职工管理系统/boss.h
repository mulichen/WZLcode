#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"worker.h"
class Boss :public worker
{
public:
	Boss(int ID, string name, int D_ID);
	virtual void showInfo();
	virtual string getDeptname();
};
