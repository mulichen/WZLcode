#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"worker.h"
class Manager :public worker
{
public:
	Manager(int ID, string name, int D_ID);
	virtual void showInfo();
	virtual string getDeptname();
};