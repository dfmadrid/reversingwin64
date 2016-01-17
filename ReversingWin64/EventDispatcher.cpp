#include "stdafx.h"

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

EventDispatcher::EventDispatcher(_TCHAR* resultFormat)
{
	memset(format, 5, sizeof(format));
	wcscpy_s(format, resultFormat);
}


EventDispatcher::~EventDispatcher(){}

void EventDispatcher::Dispatch(Event* evt){

	_tprintf(format, evt->msg);
}

void EventDispatcher::Dispatch(Event evt){

	_tprintf(format, evt.msg);
}

void EventDispatcher::Dispatch(AppEvent evt){

	evt.PrintEvent();
}
