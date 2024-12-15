#include "logger.h"

ILogger& Logger::getInstance()
{
    std::call_once(_initFlag, []()
    {
       _logger = std::unique_ptr<ILogger>(new Logger());
    });
    return *_logger;
}

void Logger::setInstance(std::unique_ptr<ILogger>&& logger)
{
    if(_logger == nullptr)
    {
        _logger = std::move(logger);
    }
}

ILogger& Logger::operator<<(LogType& type)
{
    switch(type)
    {
    case DEBUG: break;
    case INFO: break;
    case WARNING: break;
    case ERROR: break;
    case FATAL: break;
    }

    return *_logger;
}
