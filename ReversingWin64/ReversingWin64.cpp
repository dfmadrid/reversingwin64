// ReversingWin64.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void invokeAFunction(int rdx, double xmm1, _TCHAR* r9)
{
	_TCHAR* msg = _T("Calling a function with 4 arguments: %d %g %s \n");
	_tprintf(msg, rdx, xmm1, r9);
}

int _tmain(int argc, _TCHAR* argv[])
{
	_TCHAR msg[100];

	memset(msg, 0, sizeof(msg));

	invokeAFunction(3, 1.43, _T("lastArg"));

	wcscpy_s(msg, _T("Calling a function with 7 arguments: %d %d %d %d %x %s \n"));
	_tprintf(msg, 3, 5, 7, 9, 0x61, _T("lastArg"));
	
	return 0;
}

