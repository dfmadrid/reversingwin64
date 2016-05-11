#include "stdafx.h";

FileLogger::FileLogger():FileLogger(L"C:\\Temp\\log.dat"){};

FileLogger::FileLogger(LPCWSTR file){
	memset(logFile, 0, _countof(logFile) * sizeof(_TCHAR));
	_tcscpy_s(logFile, _countof(logFile), file);
}

void FileLogger::logMsg(byte* msg){
	HANDLE hFile;
	DWORD dwBytesWritten = 0;
	DWORD dwBytesToWrite = (DWORD)64;

	hFile = CreateFile(logFile,
		FILE_APPEND_DATA,
		0,                      
		NULL,                  
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,  
		NULL);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("Unable to open log file \"%s\" for write.\n"), logFile);
		return;
	}

	if ((WriteFile(hFile, msg, dwBytesToWrite, &dwBytesWritten, NULL) == FALSE) && dwBytesWritten != dwBytesToWrite)
		_tprintf(_T("Unable to write to log file \"%s\".\n"), logFile);
	
	CloseHandle(hFile);
}

FileLogger::~FileLogger(){}