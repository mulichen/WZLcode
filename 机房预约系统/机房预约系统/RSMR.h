#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"student.h"
#include"teacher.h"
#include"manager.h"
#include"globallfile.h"
#include<fstream>
//�˵�
void menu();

//��½����
void loginIn(string filename,int type);

//����Աģ��
void  manager(Identity* &manager);

//ѧ��ģ��
void student(Identity* &student);



