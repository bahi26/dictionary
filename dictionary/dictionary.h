#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "GADDAG.h"
using namespace std;

struct Word {
	string word;
	string rack;
	pair<int, int> location; //(y,x) ==(row,column)
	int direction;  //   0= horizontal  1=vertical
};

class dictionary
{
	GADDAG data;
public:
	

	dictionary();
	dictionary(std::string filename);

	void search(std::string board,std::string word);
	void search(std::string board, std::string word,int index);
	bool check(std::string word);
	void selectAll(std::string word);
	vector<pair<pair<string, string>, int>> get_return_vector();
	pair<int, char> get_index_of_ch(string row, string word, int index);
	vector<Word> divide_the_board(int board[15][15], string rack);
	
	void test();

	

	~dictionary();
	
};

