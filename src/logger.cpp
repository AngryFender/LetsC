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

void Logger::registerDebugCallback(const LogDebug logDebug)
{
    if(logDebug)
    {
        _logDebug = logDebug;
    }
}

void Logger::registerInfoCallback(const LogInfo logInfo)
{
    if(logInfo)
    {
        _logInfo = logInfo;
    }
}

void Logger::registerWarningCallback(const LogWarning logWarning)
{
    if(logWarning)
    {
        _logWarning = logWarning;
    }}

void Logger::registerErrorCallback(const LogError logError)
{
    if(logError)
    {
        _logError = logError;
    }
}

void Logger::registerFatalCallback(const LogFatal logFatal)
{
    if(logFatal)
    {
        _logFatal = logFatal;
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
