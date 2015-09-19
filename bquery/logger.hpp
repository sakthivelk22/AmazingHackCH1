#ifndef __LOGGER_HPP
#define __LOGGER_HPP

#ifndef __DEBUG__
#define __DEBUG__ 0
#endif

#include <string>
#include <cstddef>
#include <iostream>
#include <fstream>
#include <cstddef>
#include <ctime>
#include <cstring>

using namespace std;

namespace _level
{
enum  LogLevel 
{ SEVERE, WARNING, INFO, DEBUG, FINE, FINER, FINEST};

string toString(LogLevel level)
{
    switch(level)
    {
    case SEVERE:
        return "SEVERE";;
    case WARNING:
        return "WARNING";;
    case INFO:
        return "INFO";;
    case DEBUG:
        return "DEBUG";;
    case FINE:
        return "FINE";;
    case FINER:
        return "FINER";;
    case FINEST:
        return "FINEST";;
    default:
        return "INFO";;
    }
}
}

namespace _logger
{

class Logger
{
	private:
		static Logger *logInstance;
		string fileName;
		std::ifstream is;
		
		Logger(string outFile) 
		{
			fileName=outFile;
			std::filebuf* buf = is.rdbuf();
			buf->open(fileName.c_str(),std::ios_base::out|std::ios_base::app);
			std::clog.rdbuf(buf);
		}
		Logger(const Logger& logger){}
		Logger operator=(const Logger& logger){ /*Making Private*/ return *this;}
		~Logger()
		{
			delete logInstance;
		}
	public:
		static Logger* getInstance(string outFile)
		{
			if (logInstance && outFile != logInstance->getFileName()) 
			{
					delete logInstance;
					logInstance = 0;
			}
			if (!logInstance) Logger::logInstance = new Logger(outFile);
			return logInstance;
		}
		string getFileName()
		{
			return this->fileName;
		}
		
		void log(_level::LogLevel level,string message)
		{
			if (__DEBUG__ &&level>_level::INFO)
                std::clog<<getDateTimeStamp()<<"\t"<<toString(level)<<std::endl<<"\t"<<message<<std::endl;
			else if (level <= _level::INFO)
				std::clog<<getDateTimeStamp()<<"\t"<<toString(level)<<" : "<<message<<std::endl;
		}		
        
		string getDateTimeStamp()
		{
			time_t rawtime = time(0);
			struct tm *timestruct = localtime(&rawtime);
			char * value = asctime(timestruct);
            char* replace = strchr(value,'\n') ;
            replace[0]='\0';
            return value;
            
		}
};

Logger* Logger::logInstance = 0;
}

#endif // __LOGGER_HPP
