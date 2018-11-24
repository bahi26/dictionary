#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include<vector>
#include "GADDAG.h"
#include "Move.h"
using namespace std;
class dictionary
{
	GADDAG data;
	vector<Move>returnVec;
public:
	dictionary();
	dictionary(std::string filename);

	void search(std::string board,std::string word);
	void search(std::string board, std::string word,int index);
	bool check(std::string word);
	bool selectAll(std::string word);
	vector<string>cast(int board[15][15]);
	void test();

	void execute(int board[15][15],string rack);

	~dictionary();
	
};

