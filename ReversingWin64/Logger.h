
struct EventTime{
	WORD day;
	WORD month;
	WORD year;
	WORD hour;
	WORD minute;
};

class BaseLogger{

public:
	BaseLogger();
	virtual ~BaseLogger();
	virtual void logMsg(byte* msg);
};

class FileLogger : public BaseLogger{
public:
	FileLogger();
	~FileLogger();
	FileLogger(LPCWSTR path);
	void logMsg(byte* msg);
private:
	_TCHAR logFile[256];
};

class BaseEvent{
public:
	char rawData[32];
	byte eventData[64];
	BaseEvent();
	virtual ~BaseEvent();
	virtual void prepareEvent();
};

class AppEvent:public BaseEvent{
public:
	AppEvent();
	~AppEvent();
	void prepareEvent();
private:
	int eventCount;
};