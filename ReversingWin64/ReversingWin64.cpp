// ReversingWin64.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int multibyteToAscii(_TCHAR* mbStr, char* asciiStr)
{
	char wideChar[2];
	char* wideCharPtr = wideChar;
	int i = 0;

	for (i; i < _tcslen(mbStr); i++){
		wideCharPtr = (char *) &mbStr[i];
		asciiStr[i] = *(wideCharPtr++);
	}

	return i;
}

int multibyteToAscii2(_TCHAR* mbStr, char* asciiStr)
{
	int i = 0;

	for (i; i < _tcslen(mbStr); i++){
		asciiStr[i] = mbStr[i]++;
	}

	return i;
}

int _tmain(int argc, _TCHAR* argv[])
{
	_TCHAR inStr[20];
	size_t charsRead = 0;
	char outStr[20];

	memset(inStr, 0, sizeof(inStr));
	memset(outStr, 0, sizeof(outStr));

	_cgetws_s(inStr, sizeof(inStr), &charsRead);

	if (charsRead > 0){
		multibyteToAscii3(inStr, outStr);
		printf("The ascii string received as input is %s \n", outStr);
	}

	return 0;
}

