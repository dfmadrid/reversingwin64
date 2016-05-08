#include "stdafx.h";

BaseLogger::BaseLogger(){

	//format = new char[50];
	//memset(format, 0, 50);
	//strcpy_s(format, 50, "The ascii string received as input is %s \n");
}

BaseLogger::BaseLogger(char* formatStr){

	size_t msgSize = strnlen_s(formatStr, 256);

	//format = new char[msgSize];
	//memset(format, 0, msgSize);
	//strcpy_s(format, msgSize, formatStr);
}

void BaseLogger::logMsg(char* msg){

	printf("The ascii string received as input is %s \n", msg);
}

BaseLogger::~BaseLogger() {};