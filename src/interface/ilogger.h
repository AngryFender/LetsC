#ifndef ILOGGER_H
#define ILOGGER_H

enum LogType
{
    DEBUG = 0,
    INFO,
    WARNING,
    ERROR,
    FATAL
};

class ILogger
{
public:
    virtual ~ILogger() = default;
    virtual ILogger& operator << (LogType& type) = 0;
};
#endif //ILOGGER_H
