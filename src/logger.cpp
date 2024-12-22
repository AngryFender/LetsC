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

ILogger& Logger::setLogLevel(const LogType& type)
{
    _logType = type;
    return *_logger;
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

ILogger& Logger::operator<<(const char* message)
{
    std::lock_guard<std::mutex> lockGuard(_mutex);
    switch(_logType)
    {
    case DEBUG: _logDebug(message);break;
    case INFO: _logInfo(message); break;
    case WARNING: _logWarning(message); break;
    case ERROR: _logError(message); break;
    case FATAL: _logFatal(message); break;
    }

    return *_logger;
}



