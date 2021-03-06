#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "dictionary.h"

using namespace std;

void yasmine()
{
	string s1, s2;
	s2 = "y";;
	vector<string>test;
	s1 = "sowpods.txt";

	GADDAG d = GADDAG();
	std::ifstream myfile(s1);
	std::string line;

	while (std::getline(myfile, line))
	{
		d.insertWord(line);
		for (int i = 0; i < s2.length(); ++i)
		{
			size_t found = line.find(s2[i]);
			if (found != string::npos && line.size()<=7)
			{
				test.push_back(line);
				break;
			}
		}
	}

	sort(test.begin(), test.end());
	d.search(s2);

	sort(d.y.begin(), d.y.end());
	vector<string> vec;
	for (int i = 0; i < d.y.size() - 1; ++i)
		if (d.y[i] != d.y[i + 1])
			vec.push_back(d.y[i]);
	if (vec[vec.size() - 1] != d.y[d.y.size() - 1])
		vec.push_back(d.y[d.y.size() - 1]);
	//EXPECT_EQ(test.size(), vec.size());
	if (test.size() != vec.size())
	{
		cout << test.size() << endl << vec.size()<<endl;
		return ;
	}
	
	for (int i = 0; i < vec.size(); i++)
	{
		if (test[i] != vec[i])
		{
			cout << test[i] << endl << vec[i] << endl;
			return;
		}
	}
}


int main()
{
/*	dictionary d("sowpods.txt");

	cout << "start" << endl;
	cout<<d.check("l")<<endl;
	*/
	yasmine();
	return 0;
}

/*  divide board into rowa and coulmns
input: 1) 2d array of integers representing the board a (0) -> z (25) and blank square (-1) board
2) arrary oef integers representing rack of player
returns vector of of strings of 15 rows and 15 coulmns
empty letter =" " space      eg: "star   computer"

void divide_the_board(int board[15][15], string rack)
{

	// sorting on rack letters


	vector <string> board_rows(15, "");
	vector <string> board_cols(15, "");

	// looping on board letters
	int rows_counter = 0;
	int coulmns_counter;
	while (rows_counter < 15) {
		coulmns_counter = 0;
		while (coulmns_counter < 15) {
			char a = ' ';
			if (board[rows_counter][coulmns_counter] != -1) a = board[rows_counter][coulmns_counter]+97;
			board_rows[rows_counter] += a;
			board_cols[coulmns_counter] += a;
			++coulmns_counter;
		}

		++rows_counter;
	}

	
	vector <word> resulted_vector_of_words;
	vector<pair<pair<string, string>, int>> returnVector;


	// sending rows to get possible words
	int return_vec_size;

	for (int ir = 0; ir < 15; ++ir) {
		d.search(board_rows[ir], rack);
		returnVector = d.get_return_vector;
		return_vec_size=returnVector.size();
		word temp_w;
		//loop over possible words
		for (int r = 0; r < return_vec_size;++r) {
			if ((rack.length() - returnVector[r].first.second.length()) == 1) {
				pair<int,char> index=get_index_of_ch(board_rows[ir],returnVector[ir].first.first, returnVector[r].second);
				string temp= board_cols[index.first];
				temp[ir] = index.second;
				d.search(temp,rack, ir);
				for (int m = 0; m < d.get_return_vector.size(); ++m) {
					
					temp_w.word = d.get_return_vector[m].first.first;
					temp_w.rack = d.get_return_vector[m].first.second;
					temp_w.location = make_pair(ir, index.first);
					temp_w.direction = 1;
					resulted_vector_of_words.push_back(temp_w);
				}
			}
			temp_w.word = returnVector[r].first.first;
			temp_w.rack = returnVector[r].first.second;
			temp_w.location = make_pair(ir, returnVector[r].second);
			temp_w.direction = 0;
			resulted_vector_of_words.push_back(temp_w);
		}
	}

	// sending columns to get possible words


	for (int ic = 0; ic < 15; ++ic) {
		d.search(board_cols[ic], rack);
		returnVector = d.get_return_vector;
		return_vec_size = returnVector.size();
		word temp_w;
		//loop over possible words
		for (int k = 0; k < return_vec_size; ++k) {
			if ((rack.length() - returnVector[k].first.second.length()) == 1) {
				pair<int, char> index = get_index_of_ch(board_rows[ic], returnVector[ic].first.first, returnVector[ic].second);
				string temp= board_rows[index.first];
				temp[ic] = index.second;
				d.search(temp, rack, ic);
				for (int m = 0; m < d.get_return_vector.size(); ++m) {

					temp_w.word = d.get_return_vector[m].first.first;
					temp_w.rack = d.get_return_vector[m].first.second;
					temp_w.location = make_pair(index.first, ic);
					temp_w.direction = 1;
					resulted_vector_of_words.push_back(temp_w);
				}
			}
			temp_w.word = returnVector[k].first.first;
			temp_w.rack = returnVector[k].first.second;
			temp_w.location = make_pair(returnVector[k].second, ic);
			temp_w.direction = 1;
			resulted_vector_of_words.push_back(temp_w);
		}
	}


}


pair<int, char>  get_index_of_ch(string row, string word, int index) {

	pair<int, char> temp = make_pair(index, ' ');
	int u = 0;
	while (index < 15) {
		if (row[index] != word[u]) {
			temp.first = index;
			temp.second = word[u];
			return temp;

		}
		
			++index; ++u;
	}

	return temp;
}*/



