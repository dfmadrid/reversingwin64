// ReversingWin64.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int multibyteToAscii(_TCHAR* mbStr, char* asciiData)
{
	int i = 0;

	for (i; i < _tcslen(mbStr); i++){
		if (sizeof(TCHAR) != sizeof(wchar_t))
		{
			return -1;
		}
		asciiData[i] = (char)mbStr[i];
	}

	return i;
}

void vtableExploit(){
	_TCHAR inStr[256];
	size_t charsRead = 0;
	FileLogger specificLogger;
	BaseLogger* logger = &specificLogger;
	AppEvent evt;
	BaseEvent* appEvt = &evt;

	memset(inStr, 0, _countof(inStr) * sizeof(_TCHAR));

	_tprintf(_T("Warning: all your keyboard input could be logged from now\n"));

	_cgetws_s(inStr, _countof(inStr) * sizeof(_TCHAR), &charsRead);

	if (charsRead > 0){
		multibyteToAscii(inStr, appEvt->rawData);
		appEvt->prepareEvent();
		logger->logMsg(appEvt->eventData);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	
	vtableExploit();

	return 0;
}

