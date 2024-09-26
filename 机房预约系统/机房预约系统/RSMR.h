#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"student.h"
#include"teacher.h"
#include"manager.h"
#include"globallfile.h"
#include<fstream>
//菜单
void menu();

//登陆功能
void loginIn(string filename,int type);

//管理员模块
void  manager(Identity* &manager);

//学生模块
void student(Identity* &student);



