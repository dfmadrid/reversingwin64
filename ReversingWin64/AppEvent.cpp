#include "stdafx.h";

AppEvent::AppEvent() {};
AppEvent::~AppEvent() {};

void AppEvent::prepareEvent(){
	SYSTEMTIME st;
	EventTime evtTime;

	GetLocalTime(&st);

	evtTime.day = st.wDay;
	evtTime.month = st.wMonth;
	evtTime.year = st.wYear;
	evtTime.hour = st.wHour;
	evtTime.minute = st.wMinute;

	memcpy(eventData, &evtTime, sizeof(evtTime));
	eventCount++;
	memcpy(eventData + sizeof(evtTime), &eventCount, sizeof(int));
	memcpy(eventData + sizeof(evtTime) + sizeof(int), rawData, strlen(rawData));
}
