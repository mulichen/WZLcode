#pragma once
#include<iostream>
using namespace std;
#include"speaker.h"
#include<string>
#include<vector>
#include<map>
#include<deque>
#include<numeric>
#include<functional>
class SpechManager
{
public:
	SpechManager();
	~SpechManager();
	void shoe_menu();
	void initspeach();
	void createspech();
	void stackspech();
	void spechdraw();
	void spechcontest();
	void showscore();
	vector<int>	F;
	vector<int> T;
	vector<int> V;
	map<int, speaker>M;
	int m_Index;
};
