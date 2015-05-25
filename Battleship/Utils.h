#ifndef GUARD_Utils_h
#define GUARD_Utils_h


//////////////////////////////////////////////////////////////////////////
// Various Utilities
//////////////////////////////////////////////////////////////////////////

#ifdef _WIN32
#	include <windows.h>
#   include <conio.h>
#endif // _WIN32

/** \brief Simple function to get non-blocking input 
*	return 0 for no input */
int getAsyncKey();

/** \brief simple function to clear command prompt */
void clearScreen();

#endif