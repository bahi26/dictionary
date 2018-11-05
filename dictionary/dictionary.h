#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "GADDAG.h"
class dictionary
{
	GADDAG data;
public:
	dictionary();
	dictionary(std::string filename);
	void search(std::string board,std::string word);
	void search(std::string board, std::string word,int index);
	bool check(std::string word);
	void test();
	~dictionary();
	
};

