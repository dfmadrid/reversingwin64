// ReversingWin64.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

bool askUser(_TCHAR* question) {
	_TCHAR answer[40];

	_tprintf(question);
	while (fgetws(answer, sizeof(answer), stdin) != NULL) {
		if (!_tcsicmp(answer, _T("Y\n"))) {
			return true;
		}
		if(!_tcsicmp(answer, _T("N\n")))
				break;
		_tprintf(question);
	}

	return false;

}

int printData(LPVOID* data, size_t length) {

	int i = 0;

	if (askUser(_T("Print reversed strings? (Y/N)"))) {
		_tprintf(_T("This is the reverse series of strings entered\n"));
		for (i = 0; i < length; i++)
			_tprintf(_T("%s\n"), (_TCHAR *) data[i]);
	}

	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	LPVOID arr[10] = { 0 };
	_TCHAR strPointer[100] = _T("\x80\x80\x80\x80\x80\x80\x80\x80\x80\x80\x80\x80\x80\x80\x80\x80\x80\x80");

	int i = 0;
	
	for (i; i < _countof(arr); i++)
		arr[i] = strPointer;

	while (askUser(_T("Do you want to reverse the array of strings? (Y/N)"))) {
		ReverseArray(arr, _countof(arr));
		printData(arr, i - 1);
	}
	return 0;
}

