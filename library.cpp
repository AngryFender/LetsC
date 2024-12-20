#include "library.h"
#include "src/logger.h"

void registerLogDebugCallback(const LogDebug callback)
{
   Logger::registerDebugCallback(callback);
}

void registerLogInfoCallback(const LogInfo callback)
{
   Logger::registerInfoCallback(callback);
}

void registerLogWarningCallback(const LogWarning callback)
{
   Logger::registerWarningCallback(callback);
}

void registerLogErrorCallback(const LogError callback)
{
   Logger::registerErrorCallback(callback);
}

void registerLogFatalCallback(const LogFatal callback)
{
   Logger::registerFatalCallback(callback);
}
