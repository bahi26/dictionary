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
void dictionary::search(std::string board, std::string word)
{
	data.returnVector.clear();
	int num = 1;
	for (int i = 0; i < board.size(); ++i)
	{
		if (board[i] == ' ')
			++num;
		else
			if (num > 0)
			{
				data.search(word, board, i, num - 1);
				num = 0;
			}
	}
}

void dictionary::search(std::string board, std::string word,int index)
{
	data.returnVector.clear();
	int num = 1;
	for (int i = 0; i < board.size(); ++i)
	{
		if (board[i] == ' ')
			++num;
		else
		{
			if (num > 0 && i == index)
			{
				data.search(word, board, i, num - 1);
				return;
			}
			num = 0;
		}
	}
}
bool dictionary::check(std::string word)
{
	return this->data.check(this->data.root, word);
}
void dictionary::test()
{

	std::string s1, s2, s3, s4,word="EEEE";
	s1 = "  all  loa    a b ";
	s2 = " all a  a  ca  ";
	s3 = "all  ";
	s4 = "a";
	/*this->data.search("alEEEEE");
	for (int i = 0; i < data.returnVector.size(); ++i)
		std::cout << data.returnVector[i].first.first << "  " << std::endl;
	return;*/

	std::cout << "word 1" << std::endl;
	search(s1, word);
	for (int i = 0; i < data.returnVector.size(); ++i)
		std::cout << data.returnVector[i].first.first << "  " << data.returnVector[i].second << "\\";
	std::cout << "word 2" << std::endl;
	search(s2, word);
	for (int i = 0; i < data.returnVector.size(); ++i)
		std::cout << data.returnVector[i].first.first << "  " << data.returnVector[i].second << "\\";
	std::cout << "word 3" << std::endl;
	search(s3, word);
	for (int i = 0; i < data.returnVector.size(); ++i)
		std::cout << data.returnVector[i].first.first << "  " << data.returnVector[i].second << "\\";
	std::cout << "word 4" << std::endl;
	search(s4, word);
	for (int i = 0; i < data.returnVector.size(); ++i)
		std::cout << data.returnVector[i].first.first << "  " << data.returnVector[i].second << "\\";
}

dictionary::~dictionary()
{
}
