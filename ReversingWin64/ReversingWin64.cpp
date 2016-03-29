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

int filterEx(unsigned int code, struct _EXCEPTION_POINTERS *ep) {

	if (code == EXCEPTION_ACCESS_VIOLATION) {
		puts("caught AV as expected.");
		return EXCEPTION_EXECUTE_HANDLER;
	}
	else {
		puts("didn't catch AV, unexpected.");
		return EXCEPTION_CONTINUE_SEARCH;
	};
}

void formatStrAbuse(TCHAR* inStr){
	
	char* asciiFormat = "The conversion to ascii of the string received as input is %s \n";
	char outStr[50];
	
	memset(outStr, 0, sizeof(outStr));

	__try{
		multibyteToAscii(inStr, outStr);
		printf(asciiFormat, outStr);
	}
	__except (filterEx(GetExceptionCode(), GetExceptionInformation())){
		_tprintf(_T("An error ocurred transforming the following input: %s\n"), inStr);
	}

}

void StackOverflow(int depth)
{
	char blockdata[8000];

	_tprintf(L"Overflow: %d\n", depth);

		StackOverflow(depth + 1);

}

void abuse(){

	for (;;)
	{
		__try
		{
			StackOverflow(0);
		}
		__except (EXCEPTION_EXECUTE_HANDLER)
		{  
			_tprintf(L"Exception handler %lX\n", _exception_code());
			//Sleep(2000);
			//exit produces fail in chkstsk, windbg stops in RtlDispatchException. If no return produces fail in chkstsk and
			// exception hanlder doesn't fires
		}
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	char buf[50] = { 0 }; 
	//formatStrAbuse(argv[1]);
	for (;;)
	{
		__try
		{
			StackOverflow(0);
		}
		__except (EXCEPTION_EXECUTE_HANDLER)
		{
  
			sprintf_s(buf, sizeof(buf), "Exception handler %lX\n", _exception_code());
			MessageBoxA(NULL, buf, "Overflow Alert!", MB_OK);

			//exit produces fail in chkstsk, windbg stops in RtlDispatchException. If no return produces fail in chkstsk and
			// exception hanlder doesn't fires
		}
	}
	

	return 0;
}
