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
#include<fstream>
#include<ctime>
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
	void savescore();
	void loadrecord();
	void showrecord();
	void claearecord();
	vector<int>	F;
	vector<int> T;
	vector<int> V;
	map<int, speaker>M;
	map<int, vector<string>>Mrcord;
	int m_Index;
	bool FIE;
};
