#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>


struct node
{
	char charcter;
	node** pointers;
	node(char c)
	{
		charcter = c;
		pointers = new node*[28];
		for (int i = 0; i < 28; ++i)
			pointers[i] = nullptr;
	}
};

class GADDAG
{	
public:
	node* root;
	std::vector<std::pair<std::string,int>> returnVector;

public:
	GADDAG();
	void insertWord(std::string &word);
	void insertChar(node* myroot, std::string &word, int start);
	void search(node *myroot,std::string word,std::string board, int start,int &golbalStart,std::string newWord,bool indector,bool check,int first);
	void deleteNodes(node* root);
	void check(node *myroot);

	~GADDAG();
};

