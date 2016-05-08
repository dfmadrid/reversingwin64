#include "stdafx.h";

FileLogger::FileLogger():FileLogger(L"C:\\Temp\\log.txt"){};

FileLogger::FileLogger(LPCWSTR file){
	logFile = new _TCHAR[92];
	memset(logFile, 0, 92);
	_tcscpy_s(logFile, 92, file);
}

FileLogger::FileLogger(LPCWSTR file, char* format):FileLogger(file){

}

void FileLogger::logMsg(char* msg){
	HANDLE hFile;
	DWORD dwBytesWritten = 0;
	DWORD dwBytesToWrite = (DWORD)strlen(msg);

	hFile = CreateFile(logFile,
		FILE_APPEND_DATA,
		0,                      
		NULL,                  
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,  
		NULL);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("Terminal failure: Unable to open file \"%s\" for write.\n"), logFile);
		return;
	}

	if ((WriteFile(hFile, msg, dwBytesToWrite, &dwBytesWritten, NULL) == FALSE) && dwBytesWritten != dwBytesToWrite)
		_tprintf(_T("Terminal failure: Unable to write to file \"%s\".\n"), logFile);
	
	CloseHandle(hFile);
}

FileLogger::~FileLogger(){
	free(logFile);
}