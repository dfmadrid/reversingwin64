
#include "stdafx.h";

BaseEvent::BaseEvent() {
	memset(rawData, 0, 40);
	memset(eventData, 0, 64);
};

BaseEvent::~BaseEvent() {};



void BaseEvent::prepareEvent(){
	memcpy(eventData, rawData, strlen(rawData));
}
