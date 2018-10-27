#include "dictionary.h"



dictionary::dictionary()
{
}

dictionary::dictionary(std::string filename)
{
	std::ifstream myfile(filename);
	std::string line;
	int i = 0;
	while (std::getline(myfile, line))
	{
		data.insertWord(line);
	//	if (++i % 5000 == 0) std::cout << line << std::endl;
	}
	//data.check(data.root);
}

dictionary::~dictionary()
{
}
