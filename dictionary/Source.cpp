#include <iostream>
#include <algorithm>
#include "dictionary.h"

using namespace std;

int main()
{
	dictionary d("sowpods.txt");
	cout << "start" << endl;
	d.test();
	return 0;
}