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

//inserting a word into an array given a line and a word
void dictionary::search(std::string board, std::string word)
{
	std::sort(word.begin(), word.end());
	reverse(word.begin(), word.end());

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

//inserting a word into an array given a line and a word and the index where you should start
void dictionary::search(std::string board, std::string word,int index)
{
	std::sort(word.begin(), word.end());
	reverse(word.begin(), word.end());
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

//checks if a word exists in an array
bool dictionary::check(std::string word)
{
	return this->data.check(this->data.root, word);
}

void dictionary::selectAll(std::string word)
{
	this->data.search(word);
}

//never mind it's just for test :D
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
vector<pair<pair<string, string>, int>>dictionary:: get_return_vector() {
	return data.returnVector;
}

pair<int, char> dictionary::get_index_of_ch(string row, string word, int index) {

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
}


/*  divide board into rowa and coulmns
input: 1) 2d array of integers representing the board a (0) -> z (25) and blank square (-1) board
2) arrary oef integers representing rack of player
returns vector of of strings of 15 rows and 15 coulmns
empty letter =" " space      eg: "star   computer"
*/
vector<Word> dictionary::divide_the_board(int board[15][15], string rack)
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
			if (board[rows_counter][coulmns_counter] != -1) a = board[rows_counter][coulmns_counter] + 97;
			board_rows[rows_counter] += a;
			board_cols[coulmns_counter] += a;
			++coulmns_counter;
		}

		++rows_counter;
	}


	vector <Word> resulted_vector_of_words;
	vector<pair<pair<string, string>, int>> returnVector;


	// sending rows to get possible words
	int return_vec_size;

	for (int ir = 0; ir < 15; ++ir) {
		search(board_rows[ir], rack);
		returnVector = get_return_vector();
		return_vec_size = returnVector.size();
		Word temp_w;


		//loop over possible words
		for (int r = 0; r < return_vec_size; ++r) {
			if ((rack.length() - returnVector[r].first.second.length()) == 1) {
				pair<int, char> index = get_index_of_ch(board_rows[ir], returnVector[ir].first.first, returnVector[r].second);
				string temp = board_cols[index.first];
				temp[ir] = index.second;
				search(temp, rack, ir);
				for (int m = 0; m < get_return_vector().size(); ++m) {

					temp_w.word = get_return_vector()[m].first.first;
					temp_w.rack = get_return_vector()[m].first.second;
					temp_w.location = make_pair(get_return_vector()[m].second, index.first);
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
		search(board_cols[ic], rack);
		returnVector = get_return_vector();
		return_vec_size = returnVector.size();
		Word temp_w;
		//loop over possible words
		for (int k = 0; k < return_vec_size; ++k) {
			if ((rack.length() - returnVector[k].first.second.length()) == 1) {
				pair<int, char> index = get_index_of_ch(board_rows[ic], returnVector[ic].first.first, returnVector[ic].second);
				string temp = board_rows[index.first];
				temp[ic] = index.second;
				search(temp, rack, ic);
				for (int m = 0; m < get_return_vector().size(); ++m) {

					temp_w.word = get_return_vector()[m].first.first;
					temp_w.rack = get_return_vector()[m].first.second;
					temp_w.location = make_pair(index.first, get_return_vector()[m].second);      //y,x
					temp_w.direction = 0;
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
;
	return resulted_vector_of_words;
}





dictionary::~dictionary()
{
}
