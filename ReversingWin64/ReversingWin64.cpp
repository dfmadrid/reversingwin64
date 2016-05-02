// ReversingWin64.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

long CALLBACK VectoredHandlder(PEXCEPTION_POINTERS ep) {

	printf("Caught exception with code %d", ep->ExceptionRecord->ExceptionCode);
	return EXCEPTION_CONTINUE_SEARCH;
}

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

void convertToAscii(TCHAR* inStr){
	
	char* asciiFormat = "The conversion to ascii of the string received as input is %s \n";
	char outStr[50];
	
	memset(outStr, 0, sizeof(outStr));

	__try{
		multibyteToAscii(inStr, outStr);
		printf(asciiFormat, outStr);
	}
	__except(EXCEPTION_EXECUTE_HANDLER){
		printf("Exception catched");
	}

}

void debuggersMustDie()
{
	__try
	{
		DebugBreak();
	}
	__except (GetExceptionCode() == EXCEPTION_BREAKPOINT ?
			EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH){
		return;
	}

	printf("Debugger detected. Ending process");
	ExitProcess(0);
}

int _tmain(int argc, _TCHAR* argv[])
{

	PVOID pV;

	// Use exceptions to detect debuggers
	debuggersMustDie();
	
	if (argc > 1)
		convertToAscii(argv[1]);
	else if (argc > 2){
		// Add application level handler
		pV = AddVectoredExceptionHandler(-1, VectoredHandlder);
		convertToAscii(argv[1]);
	}

	return 0;
}
