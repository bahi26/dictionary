#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include<vector>
#include "GADDAG.h"
using namespace std;
class dictionary
{
	GADDAG data;
public:
	dictionary();
	dictionary(std::string filename);

	void search(std::string board,std::string word);
	void search(std::string board, std::string word,int index);
	bool check(std::string word);
	bool selectAll(std::string word);
	void test();

	vector<pair<pair<string, string>, int>> get_return_vector();

	~dictionary();
	
};

