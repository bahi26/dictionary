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

	void search(std::string row_coulmn,std::string rack);
	void search(std::string row_coulmn, std::string rack,int index);
	void test(); 
	vector<pair<pair<string, string>, int>> get_return_vector();

	~dictionary();
	
};

