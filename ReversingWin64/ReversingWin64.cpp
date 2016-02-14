// ReversingWin64.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class S1
{
public:
	char m_1 = 'D';             // 1-byte element
	// 3-bytes of padding are placed here
	int m_2 = 4;           // 4-byte element
	double m_3 = 15.54;
	double m_4 = 2.503;      // 8-byte elements
};

struct strct{
	char f1 = 'E';
	int f2 = 24;
};

int _tmain(int argc, _TCHAR* argv[])
{
	char a ='A';
	char b = 'B';
	char c = 'C';
	S1 x;
	S1 z[5];
	strct strctEx;
	_TCHAR* str = _T("An example");
	_TCHAR str2[17];

	_tcscpy_s(str2, _T("A longer example"));
	int d = 2;

	printf("a = %p Alignment is %d \n", &a, __alignof(a));
	printf("b = %p Alignment is %d \n", &b, __alignof(b));
	printf("c = %p Alignment is %d \n", &c, __alignof(c));
	printf("x = %p Alignment is %d \n", &x, __alignof(x));
	printf("x.m_1 = %p Alignment is %d \n", &x.m_1, __alignof(x));
	printf("x.m_3 =  %p Alignment is %d \n", &x.m_3, __alignof(x));
	printf("z[0] = %p Alignment is %d \n", z, __alignof(z));
	printf("z[1] = %p Alignment is %d \n", &z[1], __alignof(z));
	printf("str = %p Alignment is %d \n", &str, __alignof(str));
	printf("strctEx = %p Alignment is %d \n", &strctEx, __alignof(strctEx));
	printf("str2[0] = %p Alignment is %d \n", &str2, __alignof(str2));
	printf("d = %p Alignment is %d \n", &d, __alignof(d));

	return 0;
}

