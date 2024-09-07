#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"worker.h"
class Employee:public worker
{
public:
	Employee(int ID,string name,int D_ID);
	virtual void showInfo();
	virtual string getDeptname();
};
