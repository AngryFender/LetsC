#include "library.h"
#include "src/logger.h"
#include "src/sqlite.h"

struct Sql
{
   Sqlite * sqlite;
};

void registerLogDebugCallback(const LogDebug callback)
{
   Logger::getInstance().registerDebugCallback(callback);
}

void registerLogInfoCallback(const LogInfo callback)
{
   Logger::getInstance().registerInfoCallback(callback);
}

void registerLogWarningCallback(const LogWarning callback)
{
   Logger::getInstance().registerWarningCallback(callback);
}

void registerLogErrorCallback(const LogError callback)
{
   Logger::getInstance().registerErrorCallback(callback);
}

void registerLogFatalCallback(const LogFatal callback)
{
   Logger::getInstance().registerFatalCallback(callback);
}


