// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: reference additional headers your program requires here

const int SUCCESS_MSG = 0;
const int FAIL_MSG = 1;

struct Event{
	int type;
	_TCHAR* msg;
};

class Informer{
	public:
		Informer();
		~Informer();
		void Informer::PrintEvent(Event evt);
};