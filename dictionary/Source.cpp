#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "dictionary.h"

using namespace std;



int main()
{
	dictionary d("sowpods.txt");

	cout << "start" << endl;
	cout<<d.check("l")<<endl;
	return 0;
}


