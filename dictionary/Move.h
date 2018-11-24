#include<iostream>
#include<cmath>
#include<map>
#include<vector>
#include<string>
#include <sstream>
using namespace std;
struct Move {
	string word,playedWord;
	int x, y;
	bool direction;
	bool switchMove;
	vector<char> tiles;
	Move();
	Move(int x,int y,bool direction,string playedWord, string word);
};
