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
		if (++i % 5000 == 0) std::cout << line << std::endl;
	}
	
}
void dictionary::test()
{
	data.returnVector.clear();
	std::string s1, s2, s3, s4,word="vE";
	s1 = "  all  load a b ";
	s2 = " all a  a  ca  ";
	s3 = "all  ";
	s4 = "a";
	std::cout << "word 1" << std::endl;
	data.search(word, s1, 2, 2);
	data.search(word, s1, 7, 1);
	data.search(word, s1, 12, 0);
	data.search(word, s1, 14, 0);
	for (int i = 0; i < data.returnVector.size(); ++i)
		std::cout << data.returnVector[i].first << "  " << data.returnVector[i].second << "\\";
	data.returnVector.clear();
	std::cout << "word 2" << std::endl;
	data.search(word, s2, 1, 1);
	data.search(word, s2, 5, 0);
	data.search(word, s2, 8, 1);
	data.search(word, s2, 11, 1);
	for (int i = 0; i < data.returnVector.size(); ++i)
		std::cout << data.returnVector[i].first << " " << data.returnVector[i].second << "\\";
	data.returnVector.clear();
	std::cout << "word 3" << std::endl;
	data.search(word, s3, 0, 0);
	data.search(word, s3, 5, 0);
	data.search(word, s3, 8, 1);
	data.search(word, s3, 11, 1);
	for (int i = 0; i < data.returnVector.size(); ++i)
		std::cout << data.returnVector[i].first << " " << data.returnVector[i].second << "\\";
	data.returnVector.clear();
	std::cout << "word 4" << std::endl;
	data.search(word, s4, 0, 0);
	for (int i = 0; i < data.returnVector.size(); ++i)
		std::cout << data.returnVector[i].first << " " << data.returnVector[i].second << "\\";
	data.returnVector.clear();
}

dictionary::~dictionary()
{
}
