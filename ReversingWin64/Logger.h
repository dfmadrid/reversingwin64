
class BaseLogger{

	public:
		BaseLogger();
		BaseLogger(char* format);
		virtual ~BaseLogger();
		virtual void logMsg(char* msg);
	private:
		//char* format;
};

class FileLogger : public BaseLogger{
	public:
		char outStr[65];
		FileLogger();
		~FileLogger();
		FileLogger(LPCWSTR path);
		FileLogger(LPCWSTR path, char* format);
		void logMsg(char* msg);
private:
	LPWSTR logFile;
};

