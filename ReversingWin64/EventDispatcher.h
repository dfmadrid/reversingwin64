#pragma once

const int SUCCESS_MSG = 0;
const int FAIL_MSG = 1;

struct Event{
	int type;
	_TCHAR* msg;
};

class AppEvent
{
public:
	AppEvent(Event evt);
	~AppEvent();
	void PrintEvent();
protected:
	Event event;
};

class EventDispatcher
{
public:
	EventDispatcher(_TCHAR* resultFormat);
	~EventDispatcher();
	void EventDispatcher::Dispatch(Event* evt);
	void EventDispatcher::Dispatch(Event evt);
	void EventDispatcher::Dispatch(AppEvent evt);
protected:
	_TCHAR format[100];
};

