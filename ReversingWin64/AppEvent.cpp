#include "stdafx.h"
#include "AppEvent.h"


AppEvent::AppEvent(Event evt)
{
	event = evt;
}


AppEvent::~AppEvent()
{
}

void AppEvent::PrintEvent(){

	_tprintf(event.msg);
}