#include "GADDAG.h"


GADDAG::GADDAG()
{
	this->root = new node(' ');
}

int findInVector(node** pointers, const char &c)
{
	if (c == '>')
		if (pointers[0] == nullptr)
			return -1;
		else
			return 0;
	if (c == 'E')
		if (pointers[27] == nullptr)
			return -1;
		else
			return 0;

	int temp = (int)c % 97 + 1;
	if (pointers[temp] == nullptr)
		return -1;
	else return temp;
}

int index(const char &c)
{
	if (c == '>') return 0;
	if (c == 'E') return 27;
	return (int)c % 97 + 1;
}

void GADDAG::insertWord(std::string &word)
{
	for (int i = 0; i < word.length(); ++i)
	{
		std::string fword = word.substr(0,i+1);
		std::string bword = word.substr(i+1)+'E';
		reverse(fword.begin(), fword.end());
		fword += '>';
		insertChar(this->root,fword+bword,0);
	}
}

void GADDAG::insertChar(node* myroot,std::string &word,int start)
{
	if (start < 0 || start >= word.length())
		return;
	int newStart=findInVector(myroot->pointers, word[start]);
	if (newStart == -1)
	{
		for (int i = start; i < word.length(); ++i)
		{
			myroot->pointers[index(word[i])] = new node(word[i]);
			myroot = myroot->pointers[index(word[i])];
		}
	}
	else
		insertChar(myroot->pointers[newStart], word, start + 1);
};

void GADDAG::deleteNodes(node* root)
{
	if (root==nullptr)
	{
		return ;
	}
	for (int i = 0; i < 28; ++i)
	{
		deleteNodes(root->pointers[i]);
		delete(root->pointers[i]);
	}
}

void GADDAG::search(node *myroot, std::string word,std::string board, int start, int &globalStart, std::string newWord ,bool indector,bool check,int first)
{
	//me7tag a3raf el kelma bedaytha menen aw 3ala el aa2al me4 ad eh le7ad ma 3amelt reverse
	if (myroot == nullptr)
		return;
	if (myroot->charcter == 'E'&&board[start] != ' ') return;
	//if you found a word push it in the vector
	if (myroot->charcter == 'E')
	{
		this->returnVector.push_back({ newWord,first });
		return;
	}
	//if you exceded the most right return
	if (start >= board.length()) 
		return;
	if(start<0)
	{//if your exceded the most left you have to reverce 
		if (myroot->pointers[0] != nullptr)
			{
				reverse(newWord.begin(), newWord.end());
				search(myroot->pointers[0], word, board, globalStart + 1, globalStart, newWord, true,check,0);
			}
		return;
	}

	if (board[start] != ' ')
	{
		//if you found a char on the board you must continue in your direction 
		int x = findInVector(myroot->pointers, board[start]);
		if (x < 1)
			return;
		if (!indector)
		{
			search(myroot->pointers[x], word, board, start - 1, globalStart, newWord + board[start],indector,check,first);
		}
		else
		{
			search(myroot->pointers[x], word, board, start + 1, globalStart, newWord + board[start],indector,check,first);
		}

	}
	else
	{
		
		//if the board is empty you have a choise to move forword or backword if you're moving backword
		if (indector)
		{
			check = true;
			//if you're moving forword you have to continue move forword
			for (int i = 0; i < word.length(); ++i)
			{
				if (word[i] == 'E')
				{
					for (int j = 97; j < 123; ++j)
					{
						int x = findInVector(myroot->pointers, char(j));
						if (x > 0)
						{
							std::string s1 = word;
							s1.erase(i, 1);
							search(myroot->pointers[x], s1, board, start + 1, globalStart, newWord + char(j), indector,check,first);
						}
					}
				}
				else
				{
					int x = findInVector(myroot->pointers, word[i]);
					if (x > 0)
					{
						std::string s1 = word;
						s1.erase(i, 1);
						search(myroot->pointers[x], s1, board, start + 1, globalStart, newWord + word[i], indector,check,first);
					}
				}
				
			}

		}
		else
		{
			//if you're at the moving backword you can reverse or continue backword

			for (int i = 0; i < word.length(); ++i)
			{//continue backword if possible
				if (word[i] == 'E')
				{
					for (int j = 97; j < 123; ++j)
					{
						int x = findInVector(myroot->pointers, char(j));
						if (x > 0)
						{
							std::string s1 = word;
							s1.erase(i, 1);
							search(myroot->pointers[x], s1, board, start - 1, globalStart, newWord + char(j), indector,true,first);
						}
					}
				}
				else
				{
					int x = findInVector(myroot->pointers, word[i]);
					if (x > 0)
					{
						std::string s1 = word;
						s1.erase(i, 1);
						search(myroot->pointers[x], s1, board, start - 1, globalStart, newWord + word[i],indector,true,first);
					}
				}
				
			}
			if (myroot->pointers[0] != nullptr)
			{//reverce if possible 
				reverse(newWord.begin(), newWord.end());
				search(myroot->pointers[0], word, board, globalStart + 1, globalStart, newWord, true,check,start-1);
			}
		}
	}
}

void GADDAG::check(node *myroot)
{
	if (myroot == nullptr)return;
	std::cout << myroot->charcter << std::endl;
	for (int i = 0; i < 28; ++i)
		check(myroot->pointers[i]);
}

GADDAG::~GADDAG()
{
	if(this->root!=nullptr)
		deleteNodes(root);
	this->root = nullptr;
}

