// ReversingWin64.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class msgS :public BaseLogger{
public:
	char outStr[40];
	msgS();
	msgS(char* msg);
	~msgS();
	void logMsg(char* msg);
};

msgS::msgS():msgS("starting") {};
msgS::msgS(char* msg){
	printf(msg);
}
msgS::~msgS() {};

void msgS::logMsg(char* msg){
	printf(msg);
}

__declspec(noinline) int multibyteToAscii(_TCHAR* mbStr, char* asciiStr)
{
	int i = 0;

	for (i; i < _tcslen(mbStr); i++){
		if (sizeof(TCHAR) != sizeof(wchar_t))
		{
			return -1;
		}
		*asciiStr++ = (char) *mbStr++;
	}

	return i;
}

void printMsg(char* msg, char* value){
	
	printf(msg, value);
}

void formatStrAbuse(){
	_TCHAR inStr[256];
	size_t charsRead = 0;
	FileLogger specificLogger;
	BaseLogger* logger = &specificLogger;
	msgS specificMsg;
	BaseLogger* msg = &specificMsg;

		memset(inStr, 0, _countof(inStr));

		_tprintf(_T("Enter a string to convert to ASCII:\n"));

		_cgetws_s(inStr, _countof(inStr), &charsRead);

		if (charsRead > 0){
			multibyteToAscii(inStr, specificMsg.outStr);
			logger->logMsg(specificMsg.outStr);
			msg->logMsg("asdas");
		}

}

int _tmain(int argc, _TCHAR* argv[])
{
	
	formatStrAbuse();

	return 0;
}

