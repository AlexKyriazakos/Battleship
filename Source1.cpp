#include <iostream>
using namespace std;

#include "Cell.h"

int main()
{
	Cell test[12][12];
	for (int n = 0; n<12; n++)
		for (int m = 0; m<12; m++)
		{
		test[n][m].port = true;
		test[n][m].ship = false;
		test[n][m].treasure = true;
		test[n][m].weather = 2;
		};
	
	return 0;
}