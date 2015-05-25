#include "Utils.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32



/** \brief Simple function to get non-blocking input */
int getAsyncKey()
{
	if (_kbhit()) //If exists a keyboard stroke on buffer
		return _getch(); //return character code
	else
		return 0; //no keyboard hit
}

/** \brief Function to clear command prompt with system call */
void clearScreen()
{
	system("cls");
}

#endif // _WIN32