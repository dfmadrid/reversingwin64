// ReversingWin64.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int multibyteToAscii(_TCHAR* mbStr, char* asciiStr)
{
	int i = 0;

	for (i; i < _tcslen(mbStr); i++){
		if (sizeof(TCHAR) != sizeof(wchar_t))
		{
			return -1;
		}
		asciiStr[i] = (char) mbStr[i];
	}

	return i;
}

void printMsg(char* msg, char* value){
	
	printf(msg, value);
}

void formatStrAbuse(){
	_TCHAR msg[100];
	_TCHAR inStr[95];
	size_t charsRead = 0;
	char outStr[65];
	char outMsg[100];

	memset(inStr, 0, sizeof(inStr));
	memset(outStr, 0, sizeof(outStr));
	memset(outMsg, 0, sizeof(outMsg));

	_cgetws_s(inStr, sizeof(inStr), &charsRead);

	if (charsRead > 0){
		_tcscpy_s(msg, sizeof(msg), _T("\nThe ascii string received as input is %s \n"));
		multibyteToAscii(msg, outMsg);
		multibyteToAscii(inStr, outStr);
		printMsg(outMsg, outStr);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	
	formatStrAbuse();

	return 0;
}

