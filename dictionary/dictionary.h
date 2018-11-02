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
	void test();
	~dictionary();
};

