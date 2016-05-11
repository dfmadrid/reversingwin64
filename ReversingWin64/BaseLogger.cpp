#include "stdafx.h";

BaseLogger::BaseLogger(){}


void BaseLogger::logMsg(byte* msg){

	printf("The ascii string received as input is %s \n", msg);
}

BaseLogger::~BaseLogger() {};