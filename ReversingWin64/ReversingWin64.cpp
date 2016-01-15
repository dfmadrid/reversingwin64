// ReversingWin64.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

Informer::Informer(){};
Informer::~Informer(){};
void Informer::PrintEvent(Event* evt)
{
	_tprintf(evt->msg);
}

void invokeAFunction(){

	_TCHAR* msg = _T("Calling a function with 4 arguments: %d %f %s \n");
	_tprintf(msg, 3, 1.0, _T("lastArg"));
}

int _tmain(int argc, _TCHAR* argv[])
{
	Informer informer;
	_TCHAR* msg;

	invokeAFunction();

	msg = _T("Calling a function with 7 arguments: %d %d %f %f %x %s \n");
	_tprintf(msg, 3, 5, 7.5, 5.0, 0x61, _T("lastArg"));

	msg = _T("Calling a function with 7 arguments: %d %d %d %d %x %s \n");
	_tprintf(msg, 3, 5, 7, 9, 0x61, _T("lastArg"));

	Event evt;
	evt.type = SUCCESS_MSG;
	evt.msg = _T("Program ended correctly \n");

	informer.PrintEvent(&evt);
	
	return 0;
}

