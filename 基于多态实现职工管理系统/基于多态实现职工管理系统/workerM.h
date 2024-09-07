#pragma once
#include<iostream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
using namespace std;
class Work
{
	public:
		Work();
		void show_num();
		~Work();
		int m_Empnum;
		worker** m_workarray;
		void addworker();
		void save(worker** m_workarray);
		int getnum();
		void read();
		void showworker(worker** m_workarray);
		void Locate(worker** m_workarray);
		void Modify(worker** m_workarray);
		void Sorting(worker** m_workarray);
		void CTD(worker** m_workarray);
		void DWorker(worker** m_workarray);
};