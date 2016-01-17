// ReversingWin64.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	EventDispatcher dispatcher = EventDispatcher(_T("Program ended correctly"));

	Event evt;
	evt.type = SUCCESS_MSG;
	evt.msg = _T("Program ended correctly \n");

	dispatcher.Dispatch(&evt);
	dispatcher.Dispatch(evt);

	AppEvent evtObj = AppEvent(evt);
	dispatcher.Dispatch(evtObj);
	
	return 0;
}

