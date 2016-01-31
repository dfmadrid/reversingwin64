// ReversingWin64.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void functionA(int op1, double op2, _TCHAR* op3){

	_TCHAR msg[100] = _T("Calling a function with 4 arguments: %d %f %s \n");

	_tprintf(msg, op1, op2, op3);

}

void functionB(int op1, double op2, double op3, _TCHAR* op4){

	_TCHAR msg[100] = _T("Calling a function with 5 arguments: %d %f %f %s \n");

	_tprintf(msg, op1, op2, op3, op4);
}

void functionC(int op1, double op2, double op3, int op4, int op5, _TCHAR* op6){

	_TCHAR msg[100] = _T("Calling a function with 6 arguments: %d %f %f %d %d %s \n");

	_tprintf(msg, op1, op2, op3, op4, op5, op6);
}

int invokeAFunction(){

	int opInt = 3;
	double opDouble = 7.5;
	_TCHAR* opStr = _T("lastArg");

	functionA(opInt, opDouble, opStr);
	functionB(opInt, opDouble, opDouble, opStr);
	functionC(opInt, opDouble, opDouble, opInt, opInt, opStr);

	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int result = 0;
	
	result = invokeAFunction();

	return result;
}

