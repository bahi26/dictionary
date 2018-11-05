#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "dictionary.h"

using namespace std;
struct word {
	string word = "";
	string rack = "";
	pair<int, int> location;
	int directionn;  //   0= right  1=left    2= up      3=down

};
//prototypes
void divide_the_board(int board[15][15], string rack);
int get_index_of_ch(string row, string word, int index);
//--------------------------------


//global variables
string player_rack = "";
dictionary d("sowpods.txt");
dictionary d("bahi.txt");
//-------------------------------


int main()
{
<<<<<<< HEAD
	//dictionary d("sowpods.txt");
=======
	//dictionary d("bahi.txt");
>>>>>>> 60b6c37e71ee1b056c19767e948902e056e3d055
	cout << "start" << endl;
	d.test();
	return 0;
}

/*  divide board into rowa and coulmns
input: 1) 2d array of integers representing the board a (0) -> z (25) and blank square (-1) board
2) arrary oef integers representing rack of player
returns vector of of strings of 15 rows and 15 coulmns
empty letter =" " space      eg: "star   computer"
*/
void divide_the_board(int board[15][15], string rack)
{

	// sorting on rack letters
	sort(rack.begin(), rack.end());

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
	// sending rows and coulmns to be searched
	int return_vec_size;
	for (int ir = 0; ir < 15; ++ir) {
		d.search(board_rows[ir], rack);
		returnVector = d.get_return_vector;
		return_vec_size=returnVector.size();
		for (int r = 0; r < return_vec_size;++r) {
			if ((rack.length() - returnVector[r].first.second.length()) == 1) {
				int index=get_index_of_ch(board_rows[ir],returnVector[ir].first.first, returnVector[r].second);
				d.search(board_rows[ir],rack, index);
				


			}
		}
	
	}



}


int get_index_of_ch(string row, string word, int index) {

	
	int u = 0;
	while (index < 15) {
		if (row[index] != word[u]) {
			
			return index;

		}
		
			++index; ++u;
	}

	return index;
}