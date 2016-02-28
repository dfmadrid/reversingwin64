// ReversingWin64.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int multibyteToAscii(_TCHAR* mbStr, char* asciiStr)
{
	int i = 0;

	for (i; i < _tcslen(mbStr); i++){
		if (sizeof(_TCHAR) != sizeof(wchar_t)){
			return 1;
		}
		asciiStr[i] = (char) mbStr[i];
	}

	return i;
}

int _tmain(int argc, _TCHAR* argv[])
{
	_TCHAR inStr[60];
	size_t charsRead = 0;
	char outStr[40];

	memset(inStr, 0, sizeof(inStr));
	memset(outStr, 0, sizeof(outStr));

	printf("Please enter a string");
	_cgetws_s(inStr, sizeof(inStr), &charsRead);

	if (charsRead > 0){
		multibyteToAscii(inStr, outStr);
		printf("The ascii string received as input is %s \n", outStr);
	}

	return 0;
}

